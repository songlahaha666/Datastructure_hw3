#include <iostream>
#include <cmath>
using namespace std;

struct Node {
    int coef;       // 係數
    int exp;        // 指數
    Node* link;     // 指向下一節點的指標
};

class Polynomial {
private:
    Node* head;

    void clear() {
        if (!head) return;
        Node* curr = head->link;
        while (curr != head) {
            Node* temp = curr;
            curr = curr->link;
            delete temp;
        }
        delete head;
        head = nullptr;
    }

    void copy(const Polynomial& a) {
        if (a.head == nullptr) {
            head = nullptr;
            return;
        }

        head = new Node();
        head->coef = 0;
        head->exp = -1;
        head->link = head;

        Node* temp = head;
        Node* currentA = a.head->link;

        while (currentA != a.head) {
            Node* newNode = new Node();
            newNode->coef = currentA->coef;
            newNode->exp = currentA->exp;
            temp->link = newNode;
            temp = temp->link;
            currentA = currentA->link;
        }

        temp->link = head;
    }

public:
    Polynomial() {
        head = new Node();
        head->coef = 0;
        head->exp = -1;
        head->link = head;
    }

    Polynomial(const Polynomial& a) {
        copy(a);
    }

    const Polynomial& operator=(const Polynomial& a) {
        if (this != &a) {
            clear();
            copy(a);
        }
        return *this;
    }

    ~Polynomial() {
        clear();
    }

    friend istream& operator>>(istream& is, Polynomial& x) {
        int n;
        is >> n;

        Node* temp = x.head;
        for (int i = 0; i < n; i++) {
            int coef, exp;
            is >> coef >> exp;
            Node* newNode = new Node();
            newNode->coef = coef;
            newNode->exp = exp;
            temp->link = newNode;
            temp = temp->link;
        }

        temp->link = x.head;  // 將最後一個節點鏈結到頭節點
        return is;
    }

    friend ostream& operator<<(ostream& os, Polynomial& x) {
        Node* curr = x.head->link;
        bool firstTerm = true;

        while (curr != x.head) {
            if (!firstTerm) os << " + ";
            os << curr->coef << "x^" << curr->exp;
            curr = curr->link;
            firstTerm = false;
        }

        return os;
    }

    Polynomial operator+(const Polynomial& b) const {
        Polynomial result;
        Node* temp = result.head;

        Node* pa = this->head->link;
        Node* pb = b.head->link;

        while (pa != this->head && pb != b.head) {
            Node* newNode = new Node();
            if (pa->exp > pb->exp) {
                newNode->coef = pa->coef;
                newNode->exp = pa->exp;
                pa = pa->link;
            }
            else if (pa->exp < pb->exp) {
                newNode->coef = pb->coef;
                newNode->exp = pb->exp;
                pb = pb->link;
            }
            else {
                newNode->coef = pa->coef + pb->coef;
                newNode->exp = pa->exp;
                pa = pa->link;
                pb = pb->link;
            }
            temp->link = newNode;
            temp = temp->link;
        }

        while (pa != this->head) {
            Node* newNode = new Node();
            newNode->coef = pa->coef;
            newNode->exp = pa->exp;
            temp->link = newNode;
            temp = temp->link;
            pa = pa->link;
        }

        while (pb != b.head) {
            Node* newNode = new Node();
            newNode->coef = pb->coef;
            newNode->exp = pb->exp;
            temp->link = newNode;
            temp = temp->link;
            pb = pb->link;
        }

        temp->link = result.head;  // 將最後一個節點鏈結到頭節點
        return result;
    }

    Polynomial operator-(const Polynomial& b) const {
        Polynomial result;
        Node* temp = result.head;

        Node* pa = this->head->link;
        Node* pb = b.head->link;

        while (pa != this->head && pb != b.head) {
            Node* newNode = new Node();
            if (pa->exp > pb->exp) {
                newNode->coef = pa->coef;
                newNode->exp = pa->exp;
                pa = pa->link;
            }
            else if (pa->exp < pb->exp) {
                newNode->coef = -pb->coef;
                newNode->exp = pb->exp;
                pb = pb->link;
            }
            else {
                newNode->coef = pa->coef - pb->coef;
                newNode->exp = pa->exp;
                pa = pa->link;
                pb = pb->link;
            }
            temp->link = newNode;
            temp = temp->link;
        }

        while (pa != this->head) {
            Node* newNode = new Node();
            newNode->coef = pa->coef;
            newNode->exp = pa->exp;
            temp->link = newNode;
            temp = temp->link;
            pa = pa->link;
        }

        while (pb != b.head) {
            Node* newNode = new Node();
            newNode->coef = -pb->coef;
            newNode->exp = pb->exp;
            temp->link = newNode;
            temp = temp->link;
            pb = pb->link;
        }

        temp->link = result.head;  // 將最後一個節點鏈結到頭節點
        return result;
    }

    Polynomial operator*(const Polynomial& b) const {
        Polynomial result;
        Node* pa = this->head->link;

        while (pa != this->head) {
            Polynomial tempPoly;
            Node* temp = tempPoly.head;
            Node* pb = b.head->link;

            while (pb != b.head) {
                Node* newNode = new Node();
                newNode->coef = pa->coef * pb->coef;  // 係數相乘
                newNode->exp = pa->exp + pb->exp;    // 指數相加
                temp->link = newNode;
                temp = temp->link;
                pb = pb->link;
            }

            temp->link = tempPoly.head;  // 將最後一個節點鏈結到頭節點
            result = result + tempPoly;
            pa = pa->link;
        }

        return result;
    }

    float Evaluate(float x) const {
        float result = 0.0;
        Node* curr = head->link;

        while (curr != head) {
            result += curr->coef * pow(x, curr->exp);
            curr = curr->link;
        }

        return result;
    }
};

int main() {
    Polynomial p1, p2;

    cout << "請輸入多項式 p1: ";
    cin >> p1;
    cout << "請輸入多項式 p2: ";
    cin >> p2;

    Polynomial sum = p1 + p2;
    Polynomial diff = p1 - p2;
    Polynomial prod = p1 * p2;

    cout << "p1 + p2 = " << sum << endl;
    cout << "p1 - p2 = " << diff << endl;
    cout << "p1 * p2 = " << prod << endl;

    float x;
    cout << "請輸入要計算的 x 值: ";
    cin >> x;
    cout << "p1(x) = " << p1.Evaluate(x) << endl;
    cout << "p2(x) = " << p2.Evaluate(x) << endl;

    return 0;
}
