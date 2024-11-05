#include <iostream>
#include <cstdlib> // Для rand() и srand()
#include <ctime>   // Для time()
#include <Windows.h>
using namespace std;

// Определение структуры узла
struct Node {
    int key;    // Ключ для идентификации узла
    int data;   // Данные узла
    Node* next; // Указатель на следующий узел
};

// Функция для создания нового узла с уникальным ключом
Node* createNode(int key, int value) {
    Node* newNode = new Node();
    newNode->key = key;
    newNode->data = value;
    newNode->next = nullptr;
    return newNode;
}

// Функция для генерации уникального ключа
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

// Функция для добавления элемента по позиции
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
        cout << "Позиция вне границ.\n";
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

//Функция посика схожих элементов
int searchCopy(Node*& head, int valur) {

}

// Функция для добавления элемента по значению (в конец списка)
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

// Функция для добавления перед указанным значением
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
        cout << "Элемент не найден.\n";
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Функция для добавления после указанного значения
void addAfterValue(Node*& head, int value, int afterValue) {
    int key = generateUniqueKey(head);
    Node* newNode = createNode(key, value);

    Node* current = head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }

    if (current == nullptr) {
        cout << "Элемент не найден.\n";
        delete newNode;
        return;
    }

    newNode->next = current->next;
    current->next = newNode;
}

// Функция для удаления элемента по позиции
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
        cout << "Позиция вне границ.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// Функция для удаления элемента по значению
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
        cout << "Элемент не найден.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// Функция для удаления перед указанным элементом
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
        cout << "Элемент не найден.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}


// Функция для удаления после указанного элемента
void deleteAfterValue(Node*& head, int afterValue) {
    Node* current = head;
    while (current != nullptr && current->data != afterValue) {
        current = current->next;
    }

    if (current == nullptr || current->next == nullptr) {
        cout << "Элемент не найден.\n";
        return;
    }

    Node* temp = current->next;
    current->next = temp->next;
    delete temp;
}

// Функция для поиска элемента по ключу
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

// Функция для поиска позиции по значению
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
    return -1; // Если элемент не найден
}

// Функция для очистки списка
void clearList(Node*& head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

// Функция для вывода списка
void printList(Node* head) {
    Node* current = head;
    unsigned short  count = 0;
    while (current != nullptr) {
        cout << count << ". (Ключ: " << current->key << ", значение: " << current->data << ") \n";
        current = current->next;
        count++;
    }
    cout << "null\n";
}

// Главная функция для демонстрации
int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Node* head = nullptr;
    srand(static_cast<unsigned>(time(0))); // Инициализация генератора случайных чисел

    int choice;
    do {
        cout << "\nМеню:\n";
        cout << "1. Добавить элемент по позиции\n";
        cout << "2. Добавить элемент в конец\n";
        cout << "3. Добавить элемент перед указанным значением\n";
        cout << "4. Добавить элемент после указанного значения\n";
        cout << "5. Удалить элемент по позиции\n";
        cout << "6. Удалить элемент по значению\n";
        cout << "7. Удалить элемент перед указанным значением\n";
        cout << "8. Удалить элемент после указанного значения\n";
        cout << "9. Поиск элемента по ключу\n";
        cout << "10. Поиск позиции по значению\n";
        cout << "11. Очистить список\n";
        cout << "12. Вывести список\n";
        cout << "13. Выйти\n";
        cout << "Ваш выбор: ";
        cin >> choice;

        int value, position, refValue, key;

        switch (choice) {
        case 1:
            cout << "Введите значение и позицию: ";
            cin >> value >> position;
            addByPosition(head, value, position);
            break;
        case 2:
            cout << "Введите значение: ";
            cin >> value;
            addByValue(head, value);
            break;
        case 3:
            cout << "Введите значение и перед каким значением вставить: ";
            cin >> value >> refValue;
            addBeforeValue(head, value, refValue);
            break;
        case 4:
            cout << "Введите значение и после какого значения вставить: ";
            cin >> value >> refValue;
            addAfterValue(head, value, refValue);
            break;
        case 5:
            cout << "Введите позицию для удаления: ";
            cin >> position;
            deleteByPosition(head, position);
            break;
        case 6:
            cout << "Введите значение для удаления: ";
            cin >> value;
            deleteByValue(head, value);
            break;
        case 7:
            cout << "Введите значение, перед которым удалить: ";
            cin >> refValue;
            deleteBeforeValue(head, refValue);
            break;
        case 8:
            cout << "Введите значение, после которого удалить: ";
            cin >> refValue;
            deleteAfterValue(head, refValue);
            break;
        case 9:
            cout << "Введите ключ для поиска: ";
            cin >> key;
            {
                Node* foundNode = searchByKey(head, key);
                if (foundNode) {
                    cout << "Элемент с ключом " << key << " найден: " << foundNode->data << "\n";
                }
                else {
                    cout << "Элемент с ключом " << key << " не найден.\n";
                }
            }
            break;
        case 10:
            cout << "Введите значение для поиска позиции: ";
            cin >> value;
            position = searchByValue(head, value);
            if (position != -1) {
                cout << "Элемент с значением " << value << " найден на позиции: " << position << "\n";
            }
            else {
                cout << "Элемент с значением " << value << " не найден.\n";
            }
            break;
        case 11:
            clearList(head);
            cout << "Список очищен.\n";
            break;
        case 12:
            printList(head);
            break;
        case 13:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Некорректный выбор, попробуйте снова.\n";
        }
    } while (choice != 13);

    // Очистка памяти перед выходом
    clearList(head);
    cout << "Hello Amir";
    return 0;
}
