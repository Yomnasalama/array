#include <bits/stdc++.h>

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

    void swap_elements(int* a, int* b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
    }

    // Rearrange an array such that arr[i] = i
    void rearrange(){                      //law rkm msh mwgod?
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(arr[j] == i){
                    swap_elements(&arr[i],&arr[j]);
                }
            }
        }
    }

    //Rearrange positive and negative numbers in O(n) time and O(1) extra space
    void sort_pos_neg(){
        int i = 0;
        for(int j = 0; j < n; j++){
            if(arr[j] < 0){
                swap_elements(&arr[i],&arr[j]);
                i++;
            }
        }
        int l = 0;
        for(int k = i; k < n; k+= 2){
            if(l < i){
                swap_elements(&arr[k],&arr[l]);
                l+=2;
            }
            else{
                break;
            }
        }
    }

    //Reorder an array according to given indexes
    void reorder(int index[]){
        int temp[n];
        for(int i = 0; i < n; i++){
            temp[index[i]] = arr[i];
        }
        for(int i = 0; i < n; i++){
            arr[i] = temp[i];
        }
        delete[]temp;
    }

    //Rearrange an array in maximum minimum form
    void max_min_form(){
        int k = 0;
        for(int i = 0; i < n / 2; i++){
            insert_element(arr[n - 1], k);
            delete_element(n);
            k+=2;
        }
    }

    //Move all negative elements to end in order with extra space allowed
    void neg_elemets_in_order(){
        int temp[n];
        int j = 0;
        for(int i = 0; i < n; i++){
            if(arr[i] >= 0){
                temp[j++] = arr[i];
            }
        }
        for(int i = 0; i < n; i++){
            if(arr[i] < 0){
                temp[j++] = arr[i];
            }
        }
        for(int i = 0; i < n; i++){
            arr[i] = temp[i];
        }
        delete [] temp;
    }

    //Replace every array element by multiplication of previous and next
    void multiplication_prev_next(){
        int temp[n];
        for(int i = 0; i < n; i++){
            if(i == 0){
                temp[i] = arr[i]*arr[i+1];
            }
            else if(i == n - 1){
                temp[i] = arr[n-1]*arr[n-2];
            }
            else{
                temp[i] = arr[i-1]*arr[i+1];
            }
        }
        for(int i = 0; i < n; i++){
            arr[i] = temp[i];
        }
        delete[]temp;
    }

    //Maximum Product Sub-array
    int maxSubarrayProduct(){
        int mul = 0;
        int res = 0;
        for(int i = 0; i < n; i++){
            mul = arr[i];
            res = max(res,mul);
            for(int j = i + 1; j < n ;j++){
                mul *= arr[j];
                res = max(res,mul);
            }

        }
        return res;
    }

    // Maximize sum of consecutive differences in a circular array
    void maxsum(){
        sort(arr,arr+n);
        int j = 1;
        int s = 0;
        for(int i = n - 1; i > n/2; i--){
            insert_element(arr[i], j);
            j+=2;
            delete_element(n - 1);
        }
        for(int i = 0; i < n - 1; i++){
            s += abs(arr[i] - arr[i+1]);
        }
        s+= abs(arr[n - 1] - arr[0]);
        cout<<s<<endl;

    }


};

int main()
{
    /*1*/
    Myarray obj;
    obj.insert_element(2,obj.n);
    obj.insert_element(0,obj.n);
    obj.insert_element(1,obj.n);
    obj.rearrange();
    obj.print_array();

    /*4*/
    Myarray obj2;
    obj2.insert_element(-1,obj2.n);
    obj2.insert_element(5,obj2.n);
    obj2.insert_element(6,obj2.n);
    obj2.insert_element(2,obj2.n);
    obj2.insert_element(-5,obj2.n);
    obj2.insert_element(-6,obj2.n);
    obj2.insert_element(-2,obj2.n);
    obj2.sort_pos_neg();
    obj2.print_array();

    /*10*/
    Myarray obj3;
    obj3.insert_element(10,obj3.n);
    obj3.insert_element(9,obj3.n);
    obj3.insert_element(5,obj3.n);
    int a[3] = {2,0,1};
    obj3.reorder(a);
    obj3.print_array();

    /*13*/
    Myarray obj4;
    obj4.insert_element(1,obj4.n);
    obj4.insert_element(2,obj4.n);
    obj4.insert_element(3,obj4.n);
    obj4.insert_element(4,obj4.n);
    obj4.insert_element(5,obj4.n);
    obj4.insert_element(6,obj4.n);
    obj4.max_min_form();
    obj4.print_array();

    /*16*/
    Myarray obj5;
    obj5.insert_element(1,obj5.n);
    obj5.insert_element(-1,obj5.n);
    obj5.insert_element(3,obj5.n);
    obj5.insert_element(2,obj5.n);
    obj5.insert_element(-7,obj5.n);
    obj5.insert_element(-5,obj5.n);
    obj5.insert_element(6,obj5.n);
    obj5.neg_elemets_in_order();
    obj5.print_array();

    /*191*/
    Myarray obj6;
    obj6.insert_element(2,obj6.n);
    obj6.insert_element(3,obj6.n);
    obj6.insert_element(4,obj6.n);
    obj6.insert_element(5,obj6.n);
    obj6.insert_element(6,obj6.n);
    obj6.multiplication_prev_next();
    obj6.print_array();

    /*22*/
    Myarray obj7;
    obj7.insert_element(6,obj7.n);
    obj7.insert_element(-3,obj7.n);
    obj7.insert_element(-10,obj7.n);
    obj7.insert_element(0,obj7.n);
    obj7.insert_element(2,obj7.n);
    cout<<obj7.maxSubarrayProduct();

    /*25*/
    Myarray obj8;
    obj8.insert_element(4,obj8.n);
    obj8.insert_element(2,obj8.n);
    obj8.insert_element(1,obj8.n);
    obj8.insert_element(8,obj8.n);
    obj8.maxsu();
}
