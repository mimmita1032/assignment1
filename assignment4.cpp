#include <iostream> //입출력 사용
#include <vector>   //벡터 사용
#include <string>   //문자열 사용

using namespace std; // namespace std 사용

class Book { //책 클래스
public:
    string title;  //제목
    string author; //저자

    Book(const string& title, const string& author) //생성자 제목 저자 초기화
        : title(title), author(author) {}
};

class BookManager { //책 관리 클래스
private:
    vector<Book> books; // 책 목록 저장

public:
    // 책 추가 메서드
    void addBook(const string& title, const string& author) {
        books.push_back(Book(title, author)); // book 객체 생성해서 벡터에 추가
        cout << "책이 추가되었습니다: " << title << " by " << author << endl;
    }

    // 모든 책 출력 메서드
    void displayAllBooks() const {
        if (books.empty()) {
            cout << "현재 등록된 책이 없습니다." << endl; //책이 없을 때 출력
            return;
        }

        //책 목록 출력
        cout << "현재 도서 목록:" << endl;
        for (size_t i = 0; i < books.size(); i++) { // 일반적인 for문 사용
            cout << "- " << books[i].title << " by " << books[i].author << endl;
        }
    }

    // 책 이름으로 검색
    void findBookByTitle(const string& title) const {
        for (const Book& book : books) {
            if (book.title == title) {
                cout << "책을 찾았습니다: " << book.title << " by " << book.author << endl;
                return;
            }
        }
        cout << "해당 제목의 책을 찾을 수 없습니다." << endl;
    }

    // 작가 이름으로 검색
    void findBooksByAuthor(const string& author) const {
        bool found = false;

        for (const Book& book : books) {
            if (book.author == author) {
                if (!found) {
                    cout << "해당 작가의 책 목록:" << endl;
                    found = true;
                }
                cout << "- " << book.title << endl;
            }
        }

        if (!found) {
            cout << "해당 작가의 책을 찾을 수 없습니다." << endl;
        }
    }
};

int main() {
    BookManager manager; //책 관리 객체 생성

    // 도서관 관리 프로그램의 기본 메뉴를 반복적으로 출력하여 사용자 입력을 처리합니다.
    // 프로그램 종료를 선택하기 전까지 계속 동작합니다.
    while (true) {
        cout << "\n도서관 관리 프로그램" << endl;
        cout << "1. 책 추가" << endl;             // 책 정보를 입력받아 책 목록에 추가
        cout << "2. 모든 책 출력" << endl;         // 현재 책 목록에 있는 모든 책 출력
        cout << "3. 책 제목으로 검색" << endl;     // 제목으로 검색
        cout << "4. 작가 이름으로 검색" << endl;   // 작가로 검색
        cout << "5. 종료" << endl;                 // 종료
        cout << "선택: ";

        int choice; // 사용자의 메뉴 선택을 저장
        cin >> choice;

        if (choice == 1) {
            string title, author;
            cout << "책 제목: ";
            cin.ignore(); // 이전 입력의 잔여 버퍼를 제거
            getline(cin, title);
            cout << "책 저자: ";
            getline(cin, author);
            manager.addBook(title, author);
        }
        else if (choice == 2) {
            manager.displayAllBooks();
        }
        else if (choice == 3) {
            string title;
            cout << "검색할 책 제목: ";
            cin.ignore();
            getline(cin, title);
            manager.findBookByTitle(title);
        }
        else if (choice == 4) {
            string author;
            cout << "검색할 작가 이름: ";
            cin.ignore();
            getline(cin, author);
            manager.findBooksByAuthor(author);
        }
        else if (choice == 5) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }
        else {
            cout << "잘못된 입력입니다. 다시 시도하세요." << endl;
        }
    }

    return 0; // 프로그램 정상 종료
}
