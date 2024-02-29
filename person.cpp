#include <bits/stdc++.h>
#define fl float
#define str string
#define db double
#define ll long long
using namespace std;

class QLCB{
    private:
        str name, gioitinh, street;
        int tuoi;
    public:
        void setname(str name){
            this->name = name;
        }
        str getname (){
            return this->name;
        }
        void setgioitinh(str gioitinh){
            this->gioitinh = gioitinh;
        }
        str getgioitinh () {
            return this->gioitinh;
        }
        void setstreet(str street){
            this->street = street;
        }
        str getstreet () {
            return this->street;
        }
        virtual void nhap () {
            cout << "Nhap ho ten: ";
            getline(cin, this->name);
            cout << "Nhap tuoi: ";
            cin >> this->tuoi;
            cin.ignore();
            cout << "Nhap gioi tinh: ";
            getline(cin, this->gioitinh);
            cout << "Nhap dia chi: ";
            getline(cin, this->street);
        }
        virtual void xuat () {
            cout << "Ho va ten: " << this->name << endl;
            cout << "Tuoi: " << this->tuoi << endl;
            cout << "Gioi tinh: " << this->gioitinh << endl;
            cout << "Dia chi: " << this->street << endl;
        }
};
class CongNhan : public QLCB{
    private:
        int capBac;
    public:
        void nhap () override{
            QLCB::nhap();
            cout << "Nhap cap bac cua cong nhan: ";
            cin >> this->capBac;
        }
        void xuat () override{
            cout << "Cap bac: " << this->capBac << endl;
        }
};
class KySu : public QLCB{
    private:
        str nganhdaotao;
    public:
        void nhap() override{
            QLCB::nhap();
            cout << "Nhap nganh dao tao: ";
            getline(cin, this->nganhdaotao);
        }
        void xuat() override{
            cout << "Nganh dao tao: " << this->nganhdaotao;
        }
};
class NhanVien : public QLCB{
    public:
        void nhap() override {
            QLCB::nhap();
        }
        void xuat() override {
            QLCB::xuat();
        }
};



int main(){
    vector<QLCB*> ds;
    int choice;
    do{
        cout << "=========== QUAN LY CAN BO ===========\n";
        cout << "1. Them can bo moi\n";
        cout << "2. Tim kiem theo ho ten\n";
        cout << "3. Hien thi thong tin danh sach ve can bo\n";
        cout << "4. Thoat khoi chuong trinh\n";
        cout << "Nhap lua chon cua ban: ";
        cin >> choice;
        system("cls");
        if(choice == 1){
            cin.ignore();
            int loaiCanBo;
            cout << "Chon loai can bo (1 - Cong nhan, 2 - Ky su, 3 - Nhan vien): ";
            cin >> loaiCanBo;
            cin.ignore();
            QLCB* canBo;
            switch (loaiCanBo)
            {
            case 1:
                canBo = new CongNhan();
                break;
            case 2:
                canBo = new KySu();
            default:
                canBo = new NhanVien();
                break;
            }
            canBo->nhap();
            ds.push_back(canBo);
        }else if(choice == 2){
            cin.ignore();
            str name1;
            cout << "Nhap ten nhan vien can tim kiem: ";
            getline(cin, name1);
            bool tim = false;
            for(const auto& cb :ds){
                if(cb->getname() == name1){
                    tim = true;
                    cb->xuat();
                }
            }
            if(tim == false){
                cout << "Khong co thong tin nhan vien ban vua nhap\n";
            }
        }else if (choice == 3){
            if(ds.empty()){
                cout << "Khong co nhan vien nao trong danh sach\n";
            }else{
                cout << "=============== Danh sach can bo =============== ";
                for (const auto& cb : ds) {
                        cb->xuat();
                    }
            }
        }else{
            cout << "Tam biet!!!!\n";
        }
    }while(choice != 4);
}
