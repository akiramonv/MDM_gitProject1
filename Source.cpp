#include <iostream>
#include <cstdlib> // ��� rand() � srand()
#include <ctime>   // ��� time()
#include <Windows.h>
using namespace std;

// ����������� ��������� ����
struct Node {
    int key;    // ���� ��� ������������� ����
    int data;   // ������ ����
    Node* next; // ��������� �� ��������� ����
};

// ������� ��� �������� ������ ���� � ���������� ������
Node* createNode(int key, int value) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// ������� ��� ��������� ����������� �����
int generateUniqueKey(Node* head) {
    int key;
    bool isUnique;
    do {
        key = rand();
        isUnique = true;
        Node* current = head;
        while (current != nullptr) {
            if (current->key == key) {
                isUnique = false;
                break;
            }
            current = current->next;
        }
    } while (!isUnique);
    return key;
}

// ������� ��� ���������� �������� �� �������
void addByPosition(Node*& head, int value, int position) {
    int key = generateUniqueKey(head);
    Node* newNode = createNode(key, value);

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < position - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "������� ��� ������.\n";
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

//������� ������ ������ ���������
int searchCopy(Node*& head, int valur) {

}

// ������� ��� ���������� �������� �� �������� (� ����� ������)
void addByValue(Node*& head, int value) {
    int key = generateUniqueKey(head);
    Node* newNode = createNode(key, value);

    if (!head) {
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr) {
        current = current->next;
    }
    current->next = newNode;
}

// ������� ��� ���������� ����� ��������� ���������
void addBeforeValue(Node*& head, int value, int beforeValue) {
    int key = generateUniqueKey(head);
    Node* newNode = createNode(key, value);

    if (head == nullptr) return;

    if (head->data == beforeValue) {
        newNode->next = head;
        head = newNode;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != beforeValue) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "������� �� ������.\n";
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// ������� ��� ���������� ����� ���������� ��������
void addAfterValue(Node*& head, int value, int afterValue) {
    int key = generateUniqueKey(head);
    Node* newNode = createNode(key, value);

    Node* current = head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "������� �� ������.\n";
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// ������� ��� �������� �������� �� �������
void deleteByPosition(Node*& head, int position) {
    if (head == nullptr) return;

    if (position == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    for (int i = 0; current != nullptr && i < position - 1; ++i) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "������� ��� ������.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// ������� ��� �������� �������� �� ��������
void deleteByValue(Node*& head, int value) {
    if (head == nullptr) return;

    if (head->data == value) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next != nullptr && current->next->data != value) {
        current = current->next;
    }

    if (current->next == nullptr) {
        cout << "������� �� ������.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// ������� ��� �������� ����� ��������� ���������
void deleteBeforeValue(Node*& head, int beforeValue) {
    if (head == nullptr || head->next == nullptr) return;

    if (head->next->data == beforeValue) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* current = head;
    while (current->next->next != nullptr && current->next->next->data != beforeValue) {
        current = current->next;
    }

    if (current->next->next == nullptr) {
        cout << "������� �� ������.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}


// ������� ��� �������� ����� ���������� ��������
void deleteAfterValue(Node*& head, int afterValue) {
    Node* current = head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "������� �� ������.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// ������� ��� ������ �������� �� �����
Node* searchByKey(Node* head, int key) {
    Node* current = head;
    while (current != nullptr) {
        if (current->key == key) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

// ������� ��� ������ ������� �� ��������
int searchByValue(Node* head, int value) {
    Node* current = head;
    int position = 0;
    while (current != nullptr) {
        if (current->data == value) {
            return position;
        }
        current = current->next;
        ++position;
    }
    return -1; // ���� ������� �� ������
}

// ������� ��� ������� ������
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// ������� ��� ������ ������
void printList(Node* head) {
    Node* current = head;
    unsigned short  count = 0;
    while (current != nullptr) {
        cout << count << ". (����: " << current->key << ", ��������: " << current->data << ") \n";
        current = current->next;
        count++;
    }
    cout << "null\n";
}

// ������� ������� ��� ������������
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* head = nullptr;
    srand(static_cast<unsigned>(time(0))); // ������������� ���������� ��������� �����

    int choice;
    do {
        cout << "\n����:\n";
        cout << "1. �������� ������� �� �������\n";
        cout << "2. �������� ������� � �����\n";
        cout << "3. �������� ������� ����� ��������� ���������\n";
        cout << "4. �������� ������� ����� ���������� ��������\n";
        cout << "5. ������� ������� �� �������\n";
        cout << "6. ������� ������� �� ��������\n";
        cout << "7. ������� ������� ����� ��������� ���������\n";
        cout << "8. ������� ������� ����� ���������� ��������\n";
        cout << "9. ����� �������� �� �����\n";
        cout << "10. ����� ������� �� ��������\n";
        cout << "11. �������� ������\n";
        cout << "12. ������� ������\n";
        cout << "13. �����\n";
        cout << "��� �����: ";
        cin >> choice;

        int value, position, refValue, key;

        switch (choice) {
        case 1:
            cout << "������� �������� � �������: ";
            cin >> value >> position;
            addByPosition(head, value, position);
            break;
        case 2:
            cout << "������� ��������: ";
            cin >> value;
            addByValue(head, value);
            break;
        case 3:
            cout << "������� �������� � ����� ����� ��������� ��������: ";
            cin >> value >> refValue;
            addBeforeValue(head, value, refValue);
            break;
        case 4:
            cout << "������� �������� � ����� ������ �������� ��������: ";
            cin >> value >> refValue;
            addAfterValue(head, value, refValue);
            break;
        case 5:
            cout << "������� ������� ��� ��������: ";
            cin >> position;
            deleteByPosition(head, position);
            break;
        case 6:
            cout << "������� �������� ��� ��������: ";
            cin >> value;
            deleteByValue(head, value);
            break;
        case 7:
            cout << "������� ��������, ����� ������� �������: ";
            cin >> refValue;
            deleteBeforeValue(head, refValue);
            break;
        case 8:
            cout << "������� ��������, ����� �������� �������: ";
            cin >> refValue;
            deleteAfterValue(head, refValue);
            break;
        case 9:
            cout << "������� ���� ��� ������: ";
            cin >> key;
            {
                Node* foundNode = searchByKey(head, key);
                if (foundNode) {
                    cout << "������� � ������ " << key << " ������: " << foundNode->data << "\n";
                }
                else {
                    cout << "������� � ������ " << key << " �� ������.\n";
                }
            }
            break;
        case 10:
            cout << "������� �������� ��� ������ �������: ";
            cin >> value;
            position = searchByValue(head, value);
            if (position != -1) {
                cout << "������� � ��������� " << value << " ������ �� �������: " << position << "\n";
            }
            else {
                cout << "������� � ��������� " << value << " �� ������.\n";
            }
            break;
        case 11:
            clearList(head);
            cout << "������ ������.\n";
            break;
        case 12:
            printList(head);
            break;
        case 13:
            cout << "����� �� ���������.\n";
            break;
        default:
            cout << "������������ �����, ���������� �����.\n";
        }
    } while (choice != 13);

    // ������� ������ ����� �������
    clearList(head);
    cout << "Hello Amir";
    return 0;
}
