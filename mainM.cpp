#include <iostream>

using namespace std;

class Myarray{
public:
    int capcity;
    int n;
    int* arr;
    Myarray(){
        capcity = 0;
        n = 0;
        for(int i = 0; i < n; i++){
                arr[i] = 0;
        }
    }

    void reserve(int new_capcity){
    int* temp = new int[new_capcity];
    for(int i = 0; i < n; i++){
        temp[i] = arr[i];
    }

    delete []arr;
    arr = temp;
    capcity = new_capcity;
    }

    void insert_element(int element, int idx){
	if(idx < 0 || idx > n){
		return ;
	}
	if (n == capcity){
        reserve(2 * capcity + 1);
	}

	int j = n - 1;
	while(j >= idx){
		arr[j+1] = arr[j];
		j -=1;
	}
	arr[idx] = element;
	n = n+1;
    }

    void delete_element(int idx){
	if(idx <=idx >= n)
		return ;
	int j = idx;
	while(j < n){
		arr[j] = arr[j+1];
		j+=1;
	}
	n = n-1;

	if(n < capcity/2){
        reserve(capcity / 2);
	}
}

    bool search_element(int element){
        int j = 0;
        while(j < n){
            if (arr[j] == element){
                return true;
                j+=1;
		}
	}
	return false;
    }

    void print_array(){
        int i = 0;
        while(i < n){
            cout<<arr[i]<<' ';
            i++;
        }
        cout<<endl;
    }

//Bubble sort
void sorted(){
    int i, j;
    for (i = 0; i < n-1; i++){
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++){
        if (arr[j] > arr[j+1]){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
        }
    }
}

//Rearrange array such that arr[i] >= arr[j] if i is even and arr[i] <=arr[j] if i is odd such that j < i
void sorting_even_odd(){
    sorted();
    int i = 0 , j = n-1;
    int choice = 0;
    int* temp = new int[n];
    for(int x = n-1 ; x >= 0 ; x--){
        if(x % 2 == 0){
            temp[x] = arr[i++];
        }
        else{
            temp[x] = arr[j--];
        }
    }
    delete[] arr;
    arr = temp;
}

int get_last_place(){
    for(int i = n-1 ; i >= 0 ; i--){
        if(arr[i] != 0){
            return i;
        }
    }
    return -1;
}
//Move all zeroes to end of array
void move_zeroes_end(){
    int zeroes = 0;
    for(int i = 0; i < (n-1)-zeroes; i++){
        if(arr[i] == 0){
            int last = get_last_place();
            if(last == i || last == -1){
                break;
            }
            ++zeroes;
            arr[i] = arr[last];
            arr[last] = 0;
        }
    }
}

//Rearrange an array in order - smallest, largest, 2nd smallest, 2nd largest, ..
void array_inOrder(){
    sorted();
    int i = 0 , j = n-1;
    int* temp = new int[n];
    for(int k = 0 ; k < n ; k++){
        if(k % 2 == 0){
            temp[k] = arr[i++];
        }
        else{
            temp[k] = arr[j--];
        }
    }
    delete[] arr;
    arr = temp;
}

int myCompare(string X, string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1 : 0;
}
void sort_by_string(){
    int i, j;
    for (i = 0; i < n-1; i++){
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++){
        if (myCompare(to_string(arr[j+1]),to_string(arr[j]))){
            int temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
        }
        }
    }
}
//Arrange given numbers to form the biggest number
void big_number(){
    sort_by_string();
    for(int i = 0; i<n ; i++)
        cout<<arr[i];
    cout<<endl;
}

//Positive elements at even and negative at odd positions
void positive_even_negative_odd(){
    sorted();
    int i = 0 , j = n-1;
    int* temp = new int[n];
    for(int k = 0 ; k < n ; k++){
        if(k % 2 == 0){
            temp[k] = arr[j--];
        }
        else{
            temp[k] = arr[i++];
        }
    }
    delete[] arr;
    arr = temp;
}

//Three way partitioning of an array around a given range
void partition_range(int low_val , int high_val){
    int* temp = new int[n];
    int x = 0;
    enum state{low,inRange,high};
    state s = low;
    for(int i = 0 ; i < 3 ; i++){
        if(s == low){
           for(int j = 0 ; j < n ; j++){
                if(arr[j] < low_val){
                    temp[x++] = arr[j];
                }
            }
            s = inRange;
        }
        else if(s == inRange){
            for(int j = 0 ; j < n ; j++){
                if(arr[j] >= low_val && arr[j] <= high_val){
                    temp[x++] = arr[j];
                }
            }
            s = high;
        }
        else{
            for(int j = 0 ; j < n ; j++){
                if(arr[j] > high_val){
                    temp[x++] = arr[j];
                }
            }
        }
    }
    delete[] arr;
    arr = temp;
}

//two consecutive numbers
int consecutive(){
    for(int i = 0 ; i < n-1 ; i++){
        if(arr[i] == arr[i+1]){
            return i+1;
        }
    }
    return 0;
}
//Replace two consecutive equal values with one greater
void replace_consecutive(){
    int x = consecutive();
    while(x){
        arr[x-1]+=1;
        delete_element(x);
        x = consecutive();
    }
}


};

int main()
{
    Myarray obj;
    obj.insert_element(1,obj.n);
    obj.insert_element(2,obj.n);
    obj.insert_element(3,obj.n);
    obj.insert_element(4,obj.n);
    obj.insert_element(5,obj.n);
    obj.insert_element(6,obj.n);
    obj.insert_element(7,obj.n);
    obj.print_array();
    obj.sorting_even_odd();
    obj.print_array();

    Myarray obj2;
    obj2.insert_element(1,obj2.n);
    obj2.insert_element(0,obj2.n);
    obj2.insert_element(0,obj2.n);
    obj2.insert_element(2,obj2.n);
    obj2.move_zeroes_end();
    obj2.print_array();

    obj.array_inOrder();
    obj.print_array();

    Myarray obj3;
    obj3.insert_element(54,obj3.n);
    obj3.insert_element(546,obj3.n);
    obj3.insert_element(548,obj3.n);
    obj3.insert_element(60,obj3.n);
    obj3.print_array();
    obj3.big_number();
    obj3.print_array();

    Myarray obj4;
    obj4.insert_element(1,obj4.n);
    obj4.insert_element(-3,obj4.n);
    obj4.insert_element(5,obj4.n);
    obj4.insert_element(6,obj4.n);
    obj4.insert_element(-3,obj4.n);
    obj4.positive_even_negative_odd();
    obj4.print_array();

    Myarray obj5;
    obj5.insert_element(5,obj5.n);
    obj5.insert_element(2,obj5.n);
    obj5.insert_element(1,obj5.n);
    obj5.insert_element(1,obj5.n);
    obj5.insert_element(2,obj5.n);
    obj5.insert_element(2,obj5.n);
    obj5.replace_consecutive();
    obj5.print_array();
}
