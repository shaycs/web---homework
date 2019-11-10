#include "HtmlMaker.h"
using namespace std;

int main() {
    int iter = 0;
    string colors[] { "blue", "red", "green"};
    cin >> iter;
    if (iter < 1 || iter > 50)
        cerr << "wrong number terminating\n";
    HtmlMaker hm;
    hm.OpenHtml();
    hm.OpenHead();
    hm.OpenTitle();
    hm.CloseTitle();
    hm.CloseHead();
    hm.OpenBody();
    hm.OpenTable();
    hm.OpenTHead();
    hm.CloseTHead();
    hm.OpenTBody();
    hm.OpenTRow();
    for (int i = 0; i < iter; i++) {
        hm.OpenTData(colors[i%3]);
        hm.CloseTData();
    }
    hm.CloseTRow();
    hm.CloseTBody();
    hm.CloseTable();
    hm.CloseBody();
    hm.CloseHtml();
    return 0;
}