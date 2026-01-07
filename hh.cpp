#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

int main() {
    const int MAX = 50;
    string nama[MAX];
    int qty[MAX];
    long long harga[MAX], subtotal[MAX];

    int n;
    cout << "=== KASIR MINIMARKET ===\n";
    cout << "Jumlah item (1-" << MAX << "): ";
    cin >> n;
    if (n < 1 || n > MAX) { cout << "Jumlah item tidak valid.\n"; return 0; }

    for (int i = 0; i < n; i++) {
        cout << "\nItem ke-" << i + 1 << "\n";
        cout << "Nama barang : ";   
        cin >> ws; getline(cin, nama[i]);
        cout << "Harga (Rp)  : ";
        cin >> harga[i];
        cout << "Qty         : ";
        cin >> qty[i];

        if (harga[i] < 0 || qty[i] < 0) { cout << "Input tidak boleh negatif!\n"; return 0; }
        subtotal[i] = harga[i] * 1LL * qty[i];
    }

    long long total = 0;
    for (int i = 0; i < n; i++) total += subtotal[i];

    int member; // 1 = ya, 0 = tidak
    cout << "\nMember? (1=Ya, 0=Tidak): ";
    cin >> member;

    int metode;
    cout << "Metode bayar (1=Cash, 2=QRIS, 3=Debit): ";
    cin >> metode;

    long long diskon = 0;
    if (member == 1) diskon += total * 5 / 100;          // diskon member 5%
    if (total >= 200000) diskon += total * 10 / 100;     // diskon belanja >= 200k (contoh)

    long long pajak = total * 11 / 100;                  // contoh PPN 11%
    long long grand = total + pajak - diskon;

    cout << "\n========== STRUK ==========\n";
    cout << left << setw(20) << "Barang" << right << setw(6) << "Qty"
         << setw(12) << "Harga" << setw(14) << "Subtotal" << "\n";
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < n; i++) {
        cout << left << setw(20) << nama[i]
             << right << setw(6) << qty[i]
             << setw(12) << harga[i]
             << setw(14) << subtotal[i] << "\n";
    }
    cout << "-----------------------------------------------\n";
    cout << left << setw(20) << "Total"   << right << setw(32) << total  << "\n";
    cout << left << setw(20) << "Pajak 11%"<< right << setw(32) << pajak  << "\n";
    cout << left << setw(20) << "Diskon"  << right << setw(32) << diskon << "\n";
    cout << left << setw(20) << "Grand Total" << right << setw(32) << grand << "\n";

    switch (metode) { // percabangan switch
        case 1: cout << "Pembayaran: CASH\n"; break;
        case 2: cout << "Pembayaran: QRIS\n"; break;
        case 3: cout << "Pembayaran: DEBIT\n"; break;
        default: cout << "Pembayaran: (metode tidak dikenal)\n";
    }

    long long bayar = 0;
    if (metode == 1) { // jika cash, hitung kembalian
        cout << "Uang bayar (Rp): ";
        cin >> bayar;
        if (bayar < grand) { cout << "Uang kurang!\n"; return 0; }
        cout << "Kembalian (Rp): " << (bayar - grand) << "\n";
    } else {
        cout << "Silakan proses pembayaran non-cash.\n";
    }

    cout << "Terima kasih!\n";
    return 0;
}