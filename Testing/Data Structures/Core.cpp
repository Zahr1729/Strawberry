#include <iostream>

using std::string;
using std::cout;
using std::cin;
using std::endl;

namespace CT1
{
    #pragma region Arrays

    void ExampleArray()
    {
        // An array is merely a pointer
        // the data in intArr denotes the location of the [0] term
        // intArr[k] = location of [0]th term + k
        // intArr[k] = *(intArr + k);
        // Therefore intArr[k] where k > size does not throw an error.

        // int intArr[] = { 0, 1, 2, 3 };
        // int k;
        // cin >> k;
        // cout << intArr[k] << " " << *(intArr + k) << endl;
    }

    void OverflowArray()
    {
        int arr1[] = { 0, 1, 2, 3 };
        int arr2[] = { 0, 1, 2, 3 };

        for (int i = 0; i < 8; i++)
        {
            // This goes over into arr1 because they are next to
            // each other in memory with arr2 being before arr1
            cout << arr2[i] << " ";
        }
        cout << endl;
    }

    void PointerArrays()
    {
        int arr[] = { 0, 1, 2, 3 };

        cout << arr << " " << &arr << endl;
        cout << arr + 1 << " " << &arr + 1 << endl;

        // Note that arr + 1 != &arr + 1
        // This is because arr points to first element in array
        // But &arr points to the array as a whole!
        // So arr indicates an integer, but &arr indicates an array!
    }

    void ArraySize()
    {
        // To get the size (No elements) of an array can be done in a couple ways
        int arr[] = { 0, 1, 2, 3, 4, 5, 6, 7 };

        // Get the number of bytes used in total and divide by bytes in a single element.
        cout << sizeof(arr) << " " << sizeof(*arr) << " " << sizeof(arr) / sizeof(*arr) << endl;
        cout << arr << " " << *(&arr + 1) << " " << *(&arr + 1) - arr << " " <<  endl;
        // I don't really get the second one because the answer should be 32, but I assume
        // it automatically divides by the size of the datastructure (4) to yield the correct value
    }

    #pragma endregion

    #pragma region LinkedList

    struct ListNode
    {
    public:
        int data;
        ListNode * next;

        ListNode (int _data) { data = _data; next = NULL; }
    };

    class LinkedList
    {
    public:
        ListNode * head;
        ListNode * tail;
        int size;

        LinkedList() { size = 0; head = 0; tail = 0; }

        // Add new element to end of list
        void Add (int value)
        {
            ListNode * newNode = new ListNode(value);
            if (size == 0) { head = newNode; tail = newNode; size++; return; }

            tail->next = newNode;
            tail = newNode;
            ++size;
        }

        // Place value at a given index
        void Insert (int value, int index)
        {
            if (index < 0 || index > size) { return; }

            size++;
            ListNode * newNode = new ListNode(value);
            if (index == 0) { newNode->next = head; head = newNode; return; }

            ListNode * curNode = head;
            for (int i = 0; i < (index - 1); ++i)
            {
                curNode = GetNext(curNode);
            }
            newNode->next = GetNext(curNode);
            curNode->next = newNode;
        }

        // Delete Node at given index
        void Delete (int index)
        {
            // NOT FINISHED
            if (index >= size || index < 0) return;

            size --;
            if (index == 0)
            {
                ListNode * deleteThis = head;
                head = GetNext(deleteThis);
                delete deleteThis;
                return;
            }
            
            ListNode * first = head;
            for (int i = 0; i < (index - 1); i++)
            {
                first = GetNext(first);
            }

            ListNode * second = GetNext(first);
            ListNode * third = GetNext(second);

            if (index == (size - 1)) { delete second; first->next = third; return; }

            delete second;
            first->next = third;
        }

        // Abstracted so easier for stupid humans
        int GetValue (int index)
        {
            return PrivGetValue(index, head);
        }

        // Console log the contents of array
        void Log()
        {
            ListNode * curNode = head;
            cout << "{";
            for (int i = 0; i < size; i++)
            {
                if (i != 0) cout << ", ";

                cout << curNode->data;
                curNode = GetNext(curNode);
            }
            cout << "}" << endl;
        }

    private:
        ListNode * GetNext (ListNode * curNode)
        {
            return curNode->next;
        }

        // Recursive function to get the data from the nth node in list
        int PrivGetValue (int index, ListNode * curNode)
        {
            if (index >= size || index < 0) { return -1;}

            if (curNode == NULL) { curNode = head; }
            if (index == 0) { return curNode->data; }
            return PrivGetValue(index - 1, curNode->next);
        }
    };

    void LinkedListFunc ()
    {
        LinkedList l = LinkedList();
        l.Add(4); l.Add(9); l.Add(1); l.Add(6), l.Add(10), l.Add(5);

        l.Log();

        int a; int b;
        cin >> a >> b;
        l.Insert(a, b);

        l.Log();
    }

    #pragma endregion

    #pragma region BinaryTree

    struct BTNode
    {
        int data;
        BTNode * left;
        BTNode * right;

        BTNode(int _data) { data = _data; left = NULL; right = NULL; }

        static bool IsGreater (BTNode * a, BTNode * b)
        { return a->data >= b->data; }
    };

    struct ParentChild
    {
        BTNode * parent;
        BTNode * child;
        
        ParentChild (BTNode * _parent, BTNode * _child) { parent = _parent; child = _child; }
    };

    class BinaryTree
    {
    public:
        BTNode * root;

        BinaryTree () { root = NULL; }

        void Add (BTNode * node)
        {
            if (node == NULL) return;
            if (root == NULL) { root = node; return; }

            BTNode * parent = root;
            while (true)
            {
                // If node is greater, go right.
                if (BTNode::IsGreater(node, parent))
                {
                    if (parent->right == NULL) { parent->right = node; return; }
                    parent = parent->right;
                } else {
                    if (parent->left == NULL) { parent->left = node; return; }
                    parent = parent->left;
                }
            }
        }

        // Search for a node in the tree and return it
        ParentChild Search (int value)
        {
            if (root == NULL) { return ParentChild(NULL, NULL); }
            if (root->data == value) { return ParentChild(NULL, root); }
            return PrivSearch(value, NULL, root);
        }

        // Try to delete Node with given value
        void Delete (int value)
        {
            ParentChild location = Search(value);
            if (location.child == NULL) return;

            // Edge case where at root
            if (location.parent == NULL)
            {
                root = location.child->left;
                Add(location.child->right);
                return;
            }

            // Get all necessary values
            BTNode * left = location.child->left;
            BTNode * right = location.child->right;

            // Quick hack to make adding nodes back in more efficient
            BTNode * actualroot = root;
            root = location.parent;

            // If child is to the right
            if (BTNode::IsGreater(location.child, location.parent))
            {
                // Link parent to its grandchild then add the other back in
                location.parent->right = location.child->right;
                if (location.child->left != NULL) Add(location.child->left);
            } else {    // Else
                location.parent->left = location.child->left;
                if (location.child->right != NULL) Add(location.child->right);
            }

            delete location.child;
            // Put things back in place
            root = actualroot;
        }
    
    private:

        // Added functionality to stop the HUMANS messing it up
        ParentChild PrivSearch (int value, BTNode * parent, BTNode * child)
        {
            if (child->data == value) return ParentChild(parent, child);
            if (value < child->data && child->left != NULL) return PrivSearch(value, child, child->left);
            if (value > child->data && child->right != NULL) return PrivSearch(value, child, child->right);

            return ParentChild(NULL, NULL);
        }
    };


    void BinaryTreeFunc ()
    {
        BinaryTree bt = BinaryTree();
        bt.Add(new BTNode(5)); bt.Add(new BTNode(6)); bt.Add(new BTNode(1)); bt.Add(new BTNode(4));

        int a;
        cin >> a;
        bt.Delete(a);

        ParentChild data = bt.Search(5);

        if (data.parent == NULL) { cout << "NULL "; }
        else { cout << data.parent->data << " "; }
        if (data.child == NULL) { cout << "NULL" << endl; }
        else { cout << data.child->data << endl; }
    }

    #pragma endregion

    void Core ()
    {

    }
}


int main ()
{
    CT1::Core();
    return 0;
}