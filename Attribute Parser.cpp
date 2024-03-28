#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q,i;//khai báo số lượng dòng và truy vấn
    cin>>n>>q;
    
    string temp; //sử dụng 1 chuỗi temp để lưu kết quả(dùng ở phần sau)
    vector<string> hrml; //vecto lưu trữ tag hrml
    vector<string> quer; //vecto lưu trữ truy vấn 
    cin.ignore();

//nhập vào các tag hrml
for(i=0;i<n;i++) {
    getline(cin,temp); //nhập vào tag 
    hrml.push_back(temp); //lưu trữ tag vào vecto hrml đã khai báo
}
for(i=0;i<q;i++) {
    getline(cin,temp);
    quer.push_back(temp); //lưu trữ các truy vấn 
}

map<string, string> m; //sử dụng 1 map để lưu thông tin từ hrml
vector<string> tag; //sử dụng vecto để lưu trữ các tag cần thực hiện

//vòng lặp này để xử lý các tag
for(i=0;i<n;i++) {
    temp=hrml[i];
    //xóa ký tự (")
    temp.erase(remove(temp.begin(), temp.end(), '\"' ),temp.end()); 
    //xóa kí tự ">"
    temp.erase(remove(temp.begin(), temp.end(), '>' ),temp.end());

    if(temp.substr(0,2)=="</") { //kiểm tra đã phải là tag đóng chưa
        tag.pop_back(); 
    }
    else {
        stringstream ss; //sử dụng stringstream để phân tích hrml
        ss.str(""); 
        ss<<temp; //lúc này stringstream sẽ nhận vào giá trị của temp
        string t1,t2,t3; 
        char ch;
        ss>>ch>>t1>>t2>>ch>>t3; // thao tác này để tách ra giá trị 
        //các chuỗi con trong temp
        string temp1=""; //dùng temp1 để lưu trữ tag con với tag cha
        if(tag.size()>0){ //nếu tag ko rỗng
            temp1=*tag.rbegin(); //lấy phần tử cuối của vector tag=temp1
            temp1=temp1+"."+t1; //nối thẻ t1 vào sau thẻ temp1
        }
        else{
            temp1=t1;
        }
        tag.push_back(temp1); //thêm temp1 vào vector tag 
        m[*tag.rbegin()+"~"+t2]=t3; //lưu giá trị của thuộc tính vào map
        //sử dụng tên thẻ làm khóa 
        while(ss) {
            ss>>t2>>ch>>t3;
            m[*tag.rbegin()+"~"+t2]=t3;
        }
    }

}
//xử lý lần lượt các truy vấn
for(i=0;i<q;i++){
    if (m.find(quer[i]) == m.end())
        cout << "Not Found!\n";
    else
        cout<<m[quer[i]]<<endl;
}
return 0;

}
