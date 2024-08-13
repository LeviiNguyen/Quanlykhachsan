#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <fstream>
using namespace std;

class Phong{
    protected:
        int soPhong;
        string tinhTrang, loai, huongPhong, dichVu, chuPhong;
    
    public:
        virtual int TienPhong() = 0;

        virtual void out() = 0;

        virtual void XuatFile(ofstream &file) = 0;

        void docFile(ifstream &file){
            file >> soPhong;
            file.ignore();
            getline(file,loai, ',');
            getline(file,tinhTrang, ',');
            getline(file,huongPhong, ',');
            getline(file,dichVu, ',');
            getline(file,chuPhong, ',');
            file.ignore();
        }

        void GhiFile(ofstream &file){
            file << setw(15) << left << soPhong;
            file << setw(20) << left << loai;
            file << setw(20) << left << tinhTrang;
            file << setw(20) << left << huongPhong;
            file << setw(20) << left << dichVu;
            file << setw(25) << left << chuPhong;
        }

        long PhiPhuThu(){
            int soTien = 0;
            const int HUONG_NUI = 500000;
            const int HUONG_BIEN = 750000;
            const int TIEU_CHUAN = 0;

            if(huongPhong == "Huong nui") soTien = HUONG_NUI;
            else if(huongPhong == "Huong bien") soTien = HUONG_BIEN;
            else soTien = TIEU_CHUAN;

            const int AN_UONG = 750000;
            const int DON_DEP = 200000;
            const int GIAT_UI = 200000;
            const int TRON_GOI = 1000000;
            const int KHONG = 0;

            if(dichVu == "X") return soTien + KHONG;
            else if(dichVu == "An uong") return soTien + AN_UONG;
            else if(dichVu == "Don dep") return soTien + DON_DEP;
            else if(dichVu == "Giat ui") return soTien + GIAT_UI;
            else return soTien + TRON_GOI;
        }

        void InThongTin(){
            cout << setw(15) << left << soPhong;
            cout << setw(20) << left << loai;
            cout << setw(20) << left << tinhTrang;
            cout << setw(20) << left << huongPhong;
            cout << setw(20) << left << dichVu;
            cout << setw(25) << left << chuPhong;
        }

        string GetLoai(){
            return loai;
        }

        string GetChuPhong(){
            return chuPhong;
        }

        string GetTinhTrang(){
            return tinhTrang;
        }

        string GetHuongPhong(){
            return huongPhong;
        }

        int GetSoPhong(){
            return soPhong;
        }

        void SetDichVu(string dichVu){
            this->dichVu = dichVu;
        }

        void SetChuPhong(string chuPhong){
            this->chuPhong = chuPhong;
        }

        void SetTinhTrang(string tinhTrang){
            this->tinhTrang = tinhTrang;
        }

        void TieuDe(){
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(15) << left << "So phong";
            cout << setw(20) << left << "Loai phong";
            cout << setw(20) << left << "Tinh trang";
            cout << setw(20) << left << "Huong phong";
            cout << setw(20) << left << "Dich vu";
            cout << setw(25) << left << "Chu phong";
            cout << setw(20) << left << "Tien phong" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
};

class SingleBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 1000000; // Gia goc cua phong Single Bed
            if(tinhTrang == "X") return 0;
            else return tienPhong + PhiPhuThu();
        }

        void out(){
            InThongTin();
            cout << TienPhong() << " VND";
        }

        void XuatFile(ofstream &file){
            GhiFile(file);
            file << TienPhong() << " VND";
        }
};

class DoubleBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 2000000; // Gia goc cua phong Double Bed
            if(tinhTrang == "X") return 0;
            else return tienPhong + PhiPhuThu();
        }

        void out(){
            InThongTin();
            cout << TienPhong() << " VND";
        }

        void XuatFile(ofstream &file){
            GhiFile(file);
            file << TienPhong() << " VND";
        }
};

class QueenSizeBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 4000000; // Gia goc cua phong Queen size Bed
            if(tinhTrang == "X") return 0;
            else return tienPhong + PhiPhuThu();
        }

        void out(){
            InThongTin();
            cout << TienPhong() << " VND";
        }

        void XuatFile(ofstream &file){
            GhiFile(file);
            file << TienPhong() << " VND";
        }
};

class KingSizeBed : public Phong{
    public:
        int TienPhong(){
            int tienPhong = 5500000; // Gia goc cua phong King size Bed
            if(tinhTrang == "X") return 0;
            else return tienPhong + PhiPhuThu();
        }

        void out(){
            InThongTin();
            cout << TienPhong() << " VND";
        }

        void XuatFile(ofstream &file){
            GhiFile(file);
            file << TienPhong() << " VND";
        }
};

class KhachHang{
    protected:
        int maKh, thoiGian, nguoiDiChung;
        string ten, dienThoai, email, loai, theThanhVien;

    public:
        void docFile(ifstream &file){
            file >> maKh;
            file.ignore();
            getline(file,ten, ',');
            getline(file,dienThoai, ',');
            getline(file,email, ',');
            getline(file,loai, ',');
            getline(file,theThanhVien, ',');
            file >> thoiGian;
            file.ignore();
            file >> nguoiDiChung;
            file.ignore();
        }

        void InThongTin(){
            cout << setw(10) << left << maKh;
            cout << setw(20) << left << ten;
            cout << setw(20) << left << dienThoai;
            cout << setw(25) << left << email;
            cout << setw(10) << left << loai;
            cout << setw(10) << left << theThanhVien;
            cout << setw(15) << left << thoiGian;
            cout << setw(15) << left << nguoiDiChung;
        }

        void GhiFile(ofstream &file){
            file << setw(10) << left << maKh;
            file << setw(20) << left << ten;
            file << setw(20) << left << dienThoai;
            file << setw(25) << left << email;
            file << setw(10) << left << loai;
            file << setw(10) << left << theThanhVien;
            file << setw(15) << left << thoiGian;
            file << setw(15) << left << nguoiDiChung;
        }

        void TieuDe(){
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout << setw(10) << left << "Ma KH";
            cout << setw(20) << left << "Ten KH";
            cout << setw(20) << left << "So dien thoai";
            cout << setw(25) << left << "Email";
            cout << setw(10) << left << "Loai";
            cout << setw(10) << left << "The TV";
            cout << setw(15) << left << "Thoi gian o";
            cout << setw(15) << left << "Nguoi di cung" << endl;
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }

        int GetMaKh(){
            return maKh;
        }

        string GetTen(){
            return ten;
        }

        void NhapThongTin(int id, int loai){
            maKh = id;
            cout << "Ho ten: ";
            cin.ignore();
            getline(cin,ten);
            cout << "So dien thoai: ";
            getline(cin,dienThoai);
            cout << "Email: ";
            getline(cin,email);
            if(loai == 1) this->loai = "CN";
            else if(loai == 2) this->loai = "GD";
            else this->loai = "DN";
            cout << "The thanh vien: ";
            cin >> theThanhVien;
            cout << "Thoi gian o: ";
            cin >> thoiGian;
            cout << "So nguoi di chung: ";
            cin >> nguoiDiChung;
        }

        virtual int PhiDiKem() = 0;

        int GetThoiGian(){
            return thoiGian;
        }
};

class CaNhan : public KhachHang{
    public:
        int PhiDiKem(){
            return 0;
        }
};

class GiaDinh : public KhachHang{
    public:
        int PhiDiKem(){
            return 100000 * nguoiDiChung;
        }
};

class DoanhNghiep : public KhachHang{
    public:
        int PhiDiKem(){
            return 150000 * nguoiDiChung;
        }
};

class HoaDon{
    private:
        int maPhong, tongTien = 0;
        string tenKhachHang;

    public:
        void SetTongTien(int tongTien){
            this->tongTien = tongTien;
        }

        int GetTongTien(){
            return tongTien;
        }
};

class QuanLyPhongVaKhach{
    private:
        vector <Phong*> qlp;
        vector <KhachHang*> kh;
        HoaDon hd;

    public:
        void NhapThongTin(){
            ifstream file;
			file.open("Room.csv");

            if(file.is_open()){
				int tong, n, m, k, j;
				file >> tong;
                qlp.resize(tong);
                file >> n; file >> m; file >> k; file >> j;
                file.ignore(2, '\n');
                for(int i = 0; i < n; i++)
                    qlp[i] = new SingleBed();
                for(int i = n; i < n + m; i++)
                    qlp[i] = new DoubleBed();
                for(int i = n + m; i < n + m + k; i++)
                    qlp[i] = new QueenSizeBed();
                for(int i = n + m + k; i < n + m + k + j; i++)
                    qlp[i] = new KingSizeBed();
                for(int i = 0; i < qlp.size(); i++)
                    qlp[i]->docFile(file);
				file.close();
				cout << "Doc file thanh cong \n";
			}
			else cout << "File khong mo duoc\n";
        }

        void out(){
            qlp[0]->TieuDe();
            for(int i = 0; i < qlp.size(); i++){
                qlp[i]->out();
                cout << endl;
            }
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            system("pause");
        }

        void XuatDanhSach(){
			ofstream file;
			
			file.open("Room.txt");

			if(file.is_open()){
				file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
                file << setw(15) << left << "So phong";
                file << setw(20) << left << "Loai phong";
                file << setw(20) << left << "Tinh trang";
                file << setw(20) << left << "Huong phong";
                file << setw(20) << left << "Dich vu";
                file << setw(25) << left << "Chu phong";
                file << setw(20) << left << "Tien phong" << endl;
                file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
				for(int i = 0; i < qlp.size(); i++){
					qlp[i]->XuatFile(file);
                    file << endl;
				}
                file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
				file.close();
				cout << "Ghi file thanh cong" << endl;
			}
			else cout << "File khong mo duoc" << endl;
		}

        void TimKiemPhong(int check, string name){
            system("cls");
            if(check == 1){ // Loai phong
                qlp[0]->TieuDe();
                for(int i = 0; i < qlp.size(); i++){
                    if(qlp[i]->GetLoai() == name){
                        qlp[i]->out();
                        cout << endl;
                    }
                } 
                system("pause");
            }

            if(check == 2){ // Tinh trang
                qlp[0]->TieuDe();
                for(int i = 0; i < qlp.size(); i++){
                    if(qlp[i]->GetTinhTrang() == name){
                        qlp[i]->out();
                        cout << endl;
                    }
                }
                system("pause");
            }
            if(check == 3){ // huong phong
                qlp[0]->TieuDe();
                for(int i = 0; i < qlp.size(); i++){
                    if(qlp[i]->GetHuongPhong() == name){
                        qlp[i]->out();
                        cout << endl;
                    }
                }
                system("pause");
            }
        }

        void NhapThongTinKhachHang(){
            ifstream file;
			file.open("Guest.csv");

            if(file.is_open()){
				int tong, n, m, k;
				file >> tong;
                kh.resize(tong);
                file >> n; file >> m; file >> k;
                file.ignore(2, '\n');
                for(int i = 0; i < n; i++)
                    kh[i] = new CaNhan();
                for(int i = n; i < n + m; i++)
                    kh[i] = new GiaDinh();
                for(int i = n + m; i < n + m + k; i++)
                    kh[i] = new DoanhNghiep();
                for(int i = 0; i < kh.size(); i++)
                    kh[i]->docFile(file);
				file.close();
				cout << "Doc file thanh cong \n";
			}
			else cout << "File khong mo duoc\n";
        }

        void outKhachHang(){
            kh[0]->TieuDe();
            for(int i = 0; i < kh.size(); i++){
                kh[i]->InThongTin();
                cout << endl;
            }
            cout << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
            system("pause");
        }

        void XuatDanhSachKhachHang(){
			ofstream file;
			
			file.open("Guest.txt");

			if(file.is_open()){
                file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
                file << setw(10) << left << "Ma KH";
                file << setw(20) << left << "Ten KH";
                file << setw(20) << left << "So dien thoai";
                file << setw(25) << left << "Email";
                file << setw(10) << left << "Loai";
                file << setw(10) << left << "The TV";
                file << setw(15) << left << "Thoi gian o";
                file << setw(15) << left << "Nguoi di cung" << endl;
				for(int i = 0; i < kh.size(); i++){
					kh[i]->GhiFile(file);
                    file << endl;
				}
                file << "----------------------------------------------------------------------------------------------------------------------------------------" << endl;
				file.close();
				cout << "Ghi file thanh cong" << endl;
			}
			else cout << "File khong mo duoc" << endl;
		}

        void ThemKhachHang(int loai){
            KhachHang* khachHang;

            if(loai == 1) khachHang = new CaNhan();
            else if(loai == 2) khachHang = new GiaDinh();
            else khachHang = new DoanhNghiep();

            khachHang->NhapThongTin(kh[kh.size() - 1]->GetMaKh() + 1, loai);

            kh.push_back(khachHang);
        }
        
        void ThemKhachHangVaoPhong(){
            system("cls");
            NhapThongTin();
            cout << "Cac phong con trong" << endl;
            TimKiemPhong(2, "X");

            int id;
            cout << "Chon so phong di ma : ";
            cin >> id;

            for(int i = 0; i < qlp.size(); i++){
                if(qlp[i]->GetSoPhong() == id){
                    qlp[i]->SetTinhTrang("Da dat");

                    system("cls");
                    cout << "==== Chon dich vu ===" << endl;
                    cout << "1. Khong" << endl;
        		    cout << "2. An uong" << endl;
        		    cout << "3. Don dep" << endl;
                    cout << "4. Giat ui" << endl;
                    cout << "5. Tron goi" << endl;
                    cout << "=====================" << endl;
                    cout << "Nhap lua chon cua ban: ";

                    int luaChon;
                    cin >> luaChon;

                    if(luaChon == 2) qlp[i]->SetDichVu("An uong");
                    else if(luaChon == 3) qlp[i]->SetDichVu("Don dep");
                    else if(luaChon == 4) qlp[i]->SetDichVu("Giat ui");
                    else if(luaChon == 5) qlp[i]->SetDichVu("Tron goi");

                    int loai;
                    cout << "=== Chon loai khach hang ===" << endl;
                    cout << "1. Ca nhan" << endl;
                    cout << "2. Gia dinh" << endl;
                    cout << "3. Doanh nghiep" << endl;
                    cout << "============================" << endl;
                    cout << "Nhap lua chon cua ban: ";

                    cin >> loai;
                    if(loai != 1 && loai != 2 && loai != 3){
                        cout << "Loai khach hang khong hop le!" << endl;
                        break;
                    }
                    ThemKhachHang(loai);

                    qlp[i]->SetChuPhong(kh[kh.size() - 1]->GetTen());
       
                    cout << "Da them khach hang thanh cong!" << endl;
                }
            }
        }

        void XoaKhachHang(){
            NhapThongTin();
            system("cls");
            cout << "Danh sach khach hang" << endl;
            outKhachHang();
            cout << "Nhap id khach hang muon xoa: ";
            int id;
            cin >> id;

            string name;
            for(int i = 0; i < kh.size(); i++){
                if(kh[i]->GetMaKh() == id){
                    name = kh[i]->GetTen();
                    delete kh[i];
                    kh.erase(kh.begin() + i);
                } 
            }

            for(int i = 0; i < qlp.size(); i++){
                if(qlp[i]->GetChuPhong() == name){
                    qlp[i]->SetTinhTrang("X");
                    qlp[i]->SetDichVu("X");
                    qlp[i]->SetChuPhong("X");
                }
            }

        }

        void TinhTongChiPhi(){
            hd.SetTongTien((qlp[1]->TienPhong() + kh[1]->PhiDiKem()) * kh[1]->GetThoiGian());
            cout << hd.GetTongTien();
        }
};

class MenuPhongVaKhach{
    private:
        QuanLyPhongVaKhach qlp;
    
    public:
        void HienThiMenuPhong() {
            int luaChon;

            do{
                cout << "========== MENU ==========" << endl;
        		cout << "1. Doc danh sach phong" << endl;
        		cout << "2. In danh sach phong" << endl;
        		cout << "3. Xuat danh sach phong" << endl;
                cout << "4. Tim kiem phong" << endl;
        		cout << "5. Thoat" << endl;
        		cout << "==========================" << endl;
                cout << "Nhap lua chon cua ban: ";

                cin >> luaChon;
        		switch(luaChon){
                    case 1: {
                        system("cls");
                        qlp.NhapThongTin();
                        break;
                    }

                    case 2: {
                        system("cls");
                        qlp.out();
                        system("cls");
                        break;
                    }


                    case 3: {
                        system("cls");
                        qlp.XuatDanhSach();
                        break;
                    }

                    case 4: {
                        system("cls");
                        int timKiem;
                            cout << "=== Tim kiem theo ===" << endl;
                            cout << "1. Loai Phong" << endl;
        		            cout << "2. Tinh trang" << endl;
        		            cout << "3. Huong phong" << endl;
                            cout << "4. Thoat" << endl;
                            cout << "=====================" << endl;
                            cout << "Nhap lua chon cua ban: ";

                            cin >> timKiem;
                            switch(timKiem) {
                                case 1: {
                                    system("cls");
                                    int loaiPhong;
                                    cout << "=== Chon loai phong ===" << endl;
                                    cout << "1. Single Bed" << endl;
        		                    cout << "2. Double Bed" << endl;
        		                    cout << "3. Queen Size Bed" << endl;
                                    cout << "4. King Size Bed" << endl;
                                    cout << "=======================" << endl;
                                    cout << "Nhap lua chon cua ban: ";

                                    cin >> loaiPhong;

                                    switch(loaiPhong) {
                                        case 1:
                                            qlp.TimKiemPhong(1, "Single bed");
                                            system("cls");
                                            break;
                                        
                                        case 2:
                                            qlp.TimKiemPhong(1, "Double bed");
                                            system("cls");
                                            break;
                                        
                                        case 3:
                                            qlp.TimKiemPhong(1, "Queen size bed");
                                            system("cls");
                                            break;
                                        
                                        case 4:
                                            qlp.TimKiemPhong(1, "King size bed");
                                            system("cls");
                                            break;
                                        
                                        default:
                                            cout << "Khong hop le !!!";
                                            system("cls");
                                            break;
                                    }
                                }
                                break;

                                case 2: {
                                    system("cls");
                                    int tinhTrang;
                                    cout << "=== Trang thai phong ===" << endl;
                                    cout << "1. Phong trong" << endl;
                                    cout << "2. Da dat" << endl;
                                    cout << "3. Dang su dung" << endl;
                                    cout << "========================" << endl;
                                    cout << "Nhap lua chon cua ban: ";

                                    cin >> tinhTrang;
                                    switch(tinhTrang) {
                                        case 1:
                                            qlp.TimKiemPhong(2, "X");
                                            system("cls");
                                            break;

                                        case 2:
                                            qlp.TimKiemPhong(2, "Da dat");
                                            system("cls");
                                            break;

                                        case 3:
                                            qlp.TimKiemPhong(2, "Dang su dung");
                                            system("cls");
                                            break;
                                        
                                        default:
                                            cout << "Khong hop le !!!";
                                            system("cls");
                                            break;
                                    }
                                }
                                break;

                                case 3: {
                                    system("cls");
                                    int huongPhong;
                                    cout << "=== Chon huong phong ===" << endl;
                                    cout << "1. Tieu chuan" << endl;
                                    cout << "2. Huong nui" << endl;
                                    cout << "3. Huong bien" << endl;
                                    cout << "========================" << endl;
                                    cout << "Nhap lua chon cua ban: ";

                                    cin >> huongPhong;

                                    switch(huongPhong) {
                                        case 1:
                                            qlp.TimKiemPhong(3, "Tieu chuan");
                                            system("cls");
                                            break;
                                        
                                        case 2:
                                            qlp.TimKiemPhong(3, "Huong nui");
                                            system("cls");
                                            break;

                                        case 3:
                                            qlp.TimKiemPhong(3, "Huong bien");
                                            system("cls");
                                            break;

                                        default:
                                            cout << "Khong hop le !!!";
                                            system("cls");
                                            break;
                                    }
                                }
                                break;

                                case 4:
                                    system("cls");
                                    break;

                                default:
                                    cout << "Lua chon khong hop le !!!" << endl;
                                    system("pause");
                                    system("cls");
                                    break;
                            }
                    }
                    break;

                    case 5:
                        cout << "Chuong trinh ket thuc!" << endl;
                        break;

                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                }
                cout << endl;
            } while(luaChon != 5);
        }

        void HienThiMenuKhach(){
            int luaChon;

            do{
                cout << "========== MENU ==========" << endl;
        		cout << "1. Doc danh sach khach hang" << endl;
        		cout << "2. In danh sach khach hang" << endl;
        		cout << "3. Xuat danh sach khach hang" << endl;
                cout << "4. Them khach hang" << endl;
                cout << "5. Xoa khach hang" << endl;
        		cout << "6. Thoat" << endl;
        		cout << "==========================" << endl;
                cout << "Nhap lua chon cua ban: ";

                cin >> luaChon;
        		switch(luaChon){
                    case 1: {
                        system("cls");
                        qlp.NhapThongTinKhachHang();
                        break;
                    }

                    case 2: {
                        system("cls");
                        qlp.outKhachHang();
                        system("cls");
                        break;
                    }

                    case 3: {
                        system("cls");
                        qlp.XuatDanhSachKhachHang();
                        break;
                    }

                    case 4:{
                        system("cls");
                        qlp.ThemKhachHangVaoPhong();
                        break;
                    }

                    case 5:
                        system("cls");
                        qlp.XoaKhachHang();
                        break;

                    case 6:
                        cout << "Chuong trinh ket thuc!" << endl;
                        break;

                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                }
                cout << endl;
            } while(luaChon != 6);
        }

        void MenuTong(){
            int luaChon;

            do{
                cout << "========== MENU ==========" << endl;
        		cout << "1. Thao tac voi phong" << endl;
        		cout << "2. Thao tac voi khach hang" << endl;
        		cout << "3. Thoat" << endl;
        		cout << "==========================" << endl;
                cout << "Nhap lua chon cua ban: ";

                cin >> luaChon;
        		switch(luaChon){
                    case 1: {
                        system("cls");
                        HienThiMenuPhong();
                        break;
                    }

                    case 2: {
                        system("cls");
                        HienThiMenuKhach();
                        break;
                    }

                    case 3:
                        cout << "Chuong trinh ket thuc!" << endl;
                        break;

                    default:
                        cout << "Lua chon khong hop le!" << endl;
                        break;
                }
                cout << endl;
            } while(luaChon != 3);
        }
};

int main(){
    system("cls");
    // MenuPhongVaKhach menu;
    // menu.MenuTong();
    QuanLyPhongVaKhach ql;
    ql.NhapThongTin();
    ql.NhapThongTinKhachHang();
    ql.TinhTongChiPhi();
}