#include <iostream>
using namespace std;

class SingleLinkedList {
public:
    SingleLinkedList();
    ~SingleLinkedList();

    static int counterNode;

    class Node {
    public:
        Node(int x) {
            mData = x;
            counterNode++;
        }
        ~Node() {
            cout << "Remove node with data: " << mData << endl;
        }
        int mData;
        Node* mNextNode {nullptr};
    };

    void setHeadNode(Node* node);
    Node* getHeadNode() const;

public:
    Node* createNewNode(int data);
    void pushBackNode(Node* head, int data);
    void popBackNode(Node* head);
    void insertNewNode(Node* head, int data, int pos);
    void removePosNode(Node* head, int pos);

    void showInfoNodeList();


private:
    Node* mHeadNode {nullptr};
};

int SingleLinkedList::counterNode = 0;

SingleLinkedList::SingleLinkedList() {
    if (mHeadNode == nullptr) {
        cout << "Please enter data for head node: " << endl;
        int data;
        cin >> data;
        mHeadNode = new Node(data);
    }
}

SingleLinkedList::~SingleLinkedList() {
    delete mHeadNode;
}

SingleLinkedList::Node* SingleLinkedList::getHeadNode() const {
    return mHeadNode;
}

void SingleLinkedList::setHeadNode(Node* head) {
    mHeadNode = head;
}

SingleLinkedList::Node* SingleLinkedList::createNewNode(int data) {
    Node* newNode = new Node(data);
    return newNode;
}

void SingleLinkedList::pushBackNode(Node* head, int data) {
    Node* front = head;
    while (front->mNextNode != nullptr) {
        front = front->mNextNode;
    }
    Node* newNode = new Node(data);
    front->mNextNode = newNode;
}

void SingleLinkedList::popBackNode(Node* head) {
    Node* front = head;
    while (front->mNextNode->mNextNode != nullptr) {
        front = front->mNextNode;
    }
    delete front->mNextNode;
    front->mNextNode = nullptr;
}

void SingleLinkedList::insertNewNode(Node* head, int data, int pos) {
    if (pos == counterNode) {
        pushBackNode(head, data);
    } else if (pos < 1 || pos > counterNode) {
        cout << "Invalid position." << endl;
    } else if (pos == 1) {
        Node* newNode = new Node(data);
        newNode->mNextNode = head;
        setHeadNode(newNode);
    } else {
        Node* front = head;
        Node* back = head;
        for (int i = 0; i < pos; i++) {
            front = back;
            back = back->mNextNode;
        }
        Node* newNode = new Node(data);
        front->mNextNode = newNode;
        newNode->mNextNode = back;
    }
}

void SingleLinkedList::removePosNode(Node* head, int pos) {
    if (pos == counterNode) {
        popBackNode(head);
    } else if (pos < 1 || pos > counterNode) {
        cout << "Invalid position." << endl;
    } else if (pos == 1) {
        Node* newHead = head->mNextNode;
        delete head;
        setHeadNode(newHead);
    } else {
        Node* front = head;
        Node* back = head;
        for (int i = 0; i < pos; i++) {
            front = back;
            back = back->mNextNode;
        }
        front->mNextNode = back->mNextNode;
        delete back;
    }
}

void SingleLinkedList::showInfoNodeList() {
    Node* front = mHeadNode;
    cout << "Data in node list: " << endl;
    cout << front->mData << endl;
    while (front->mNextNode != nullptr) {
        front = front->mNextNode;
        cout << front->mData << endl;
    }
}

int main() {
    SingleLinkedList *mList = new SingleLinkedList();

    do
    {
        cout << "\t\t============= OPTIONS =============" << endl;
        cout << "\t\t\t1. Push back new node" << endl;
        cout << "\t\t\t2. Pop back node" << endl;
        cout << "\t\t\t3. Insert new node" << endl;
        cout << "\t\t\t4. Remove node" << endl;
        cout << "\t\t\t5. Show information node" << endl;
        cout << "\t\t\t0. Exit" << endl;
        cout << "Please enter your option: " << endl;
        int option;
        cin >> option;

        if (option == 1) {
            cout << "Please enter data of new node: " << endl;
            int data;
            cin >> data;
            mList->pushBackNode(mList->getHeadNode(), data);
        } else if (option == 2) {
            mList->popBackNode(mList->getHeadNode());
        } else if (option == 3) {
            int data, pos;
            cout << "Please enter data: " << endl;
            cin >> data;
            cout << "Please enter pos: " << endl;
            cin >> pos;
            mList->insertNewNode(mList->getHeadNode(), data, pos);
        } else if (option == 4) {
            int pos;
            cout << "Please enter pos: " << endl;
            cin >> pos;
            mList->removePosNode(mList->getHeadNode(), pos);
        } else if (option == 5) {
            mList->showInfoNodeList();
        } else {
            break;
        }
    } while (true);
    
    return 0;
}