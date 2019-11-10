//
// Created by shayb on 11/10/2019.
//
#ifndef WEB_HTMLMAKER_H
#define WEB_HTMLMAKER_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class HtmlMaker {
private:
    ofstream file;
    int openObjects;
    string doctype = "<!DOCTYPE html>\n\n";
    string html_h = "<html>\n";
    string html_t = "</html>\n";
    string head_h = "<head>\n";
    string head_t = "</head>\n";
    string title_h = "<title>\n";
    string title_t = "</title>\n";
    string body_h = "<body style = \"margin: 0; padding: 0; height: 100vh; width: 100vw;\">\n";
    string body_t = "</body>\n";
    string table_h = "<table cellspacing = \"0\" cellpadding = \"0\" style = \"margin: 0; padding: 0; height: 100%; width: 100%;\">\n";
    string table_t = "</table>\n";
    string tableh_h = "<thead>\n";
    string tableh_t = "</thead>\n";
    string tbody_h = "<tbody style = \"margin: 0; padding: 0; height: 100%; width: 100%;\">\n";
    string tbody_t = "</tbody>\n";
    string tr_h = "<tr>\n";
    string tr_t = "</tr>\n";
    string td_h = "<td style = \"background-color: ";
    string td_t = "</td>\n";
public:
    HtmlMaker(string file_name = "index.html") : openObjects(0) {
        file.open(file_name);
        if (!file) {
            cerr << "couldn't open file terminating";
            exit(1);
        }
        file << doctype;
    }
    void FixTabs() {
        for(int i = 0; i < openObjects; i++)
            file << "\t";
    }
    void OpenHtml() {
        FixTabs();
        file << html_h;
        openObjects++;
    }
    void CloseHtml() {
        openObjects--;
        FixTabs();
        file << html_t;

    }
    void OpenBody() {
        FixTabs();
        file << body_h;
        openObjects++;
    }
    void CloseBody() {
        openObjects--;
        FixTabs();
        file << body_t;
    }
    void OpenHead() {
        FixTabs();
        file << head_h;
        openObjects++;
    }
    void CloseHead() {
        openObjects--;
        FixTabs();
        file << head_t;
    }
    void OpenTitle() {
        FixTabs();
        file << title_h;
        openObjects++;
    }
    void CloseTitle() {
        openObjects--;
        FixTabs();
        file << title_t;
    }
    void OpenTable() {
        FixTabs();
        file << table_h;
        openObjects++;
    }
    void CloseTable() {
        openObjects--;
        FixTabs();
        file << table_t;
    }
    void OpenTHead() {
        FixTabs();
        file << tableh_h;
        openObjects++;
    }
    void CloseTHead() {
        openObjects--;
        FixTabs();
        file << tableh_t;
    }
    void OpenTBody() {
        FixTabs();
        file << tbody_h;
        openObjects++;
    }
    void CloseTBody() {
        openObjects--;
        FixTabs();
        file << tbody_t;
    }
    void OpenTRow() {
        FixTabs();
        file << tr_h;
        openObjects++;
    }
    void CloseTRow() {
        openObjects--;
        FixTabs();
        file << tr_t;
    }
    void OpenTData(string color) {
        FixTabs();
        string td = td_h + color + ";\">\n";
        file << td;
        openObjects++;
    }
    void CloseTData() {
        openObjects--;
        FixTabs();
        file << td_t;
    }

};


#endif //WEB_HTMLMAKER_H
