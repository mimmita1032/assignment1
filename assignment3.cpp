#include <iostream>
using namespace std;

template<typename T>  //template선언 T는 타입을 대신하는 변수= 타입을 나중에 정하겟다
class SimpleVector //클래스의 이름simpleVector로
{
private:
	T* data;  //T타입의 값을 여러개 저장할 수 있는 배열의 시작 주소를 담는 포인터 //data는 동적 배열을 가리키는 포인터
	int currentSize;
	int currentCapacity;
	 

public:
	//기본 생성자
	SimpleVector() { //생성자이름은 클래스이름으로
		currentCapacity = 10;  //벡터가 담을 수 있는 최대 10
		currentSize = 0;       //현재 벡터에 저장된 데이터 현재 0개
		data = new T[currentCapacity]; //T타입으로 된 currentCapacity개짜리 배열을 동적 메모리 할당
		
	}

	//크기 저장하는 생성자
	SimpleVector(int capacity) {
		currentCapacity = capacity;
		currentSize = 0;
		data = new T[currentCapacity]; //data는 포인터 변수 / 동적메모리 영역에 T타입 원소를 currentCapacity만큼 저장할수 잇는 배열만듬
		
	}
	
	//push_back 함수 선언과  구현
	void push_back(const T& value) { //왜 여기만 매개변수 잇고 팝백엔 없?????????
		if (currentSize < currentCapacity) { //현재크기가 용량보다 작으면
			data[currentSize] = value;       //배열 맨 끝에 값 저장
			currentSize++;                   //새 원소 추가했으니 실제 저장된 원소 개수 1증가,
		}
	
		//꽉 찼으면 아무 동작도 하지 않음
	}

	//마지막 원소를 "제거"하는 함수
	void pop_back() { //그냥 끝에서 지우는거라 매개변수 필요없음 호출만
		if (currentSize > 0) {
			currentSize--;  // 마지막 원소 무시
		}
		// 아무 원소도 없으면 아무 동작도 하지 않음
	}
	int capacity() const {   //클래스 밖에서 벡터의 currentCapacity를 외부에서 읽을 수 있게 해주는 함수
		return currentCapacity;
	}
	int size() const { 
		return currentSize;
	}
	~SimpleVector() { //소멸자의 이름은 클래스의 이름, delete[] 포인터; 형태가 표준, 포인터없다면 비워둠
		delete[] data; //data는 new[]로 할당해서 []로 지워야함
	}
};
int main() {
	SimpleVector<int> vec;
	vec.push_back(1);
	vec.push_back(2);
	vec.push_back(3); //3을 벡터 끝에 넣겟다
	vec.pop_back();
	cout << vec.size() << " " << vec.capacity() << endl;
	

	
}