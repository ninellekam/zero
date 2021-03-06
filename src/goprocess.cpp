#include "../inc/goprocess.h"

void    Gopro::adddprtmnt(std::string name){
    c = new Adddep(name);
    c->set_company(&com);
    c->redo();
    Do_Com.push_back(c);
}
void    Gopro::addwrkr(std::string depn, std::string s,
std::string f,
std::string m,
std::string func, int sal) {
    c = new AddWorker(depn,s,f,m,func,sal);
    c->set_company(&com);
    c->redo();
    Do_Com.push_back(c);
}

void    Gopro::fadddprtmnt(std::string name){
    c = new Fadddep(name);
    c->set_company(&com);
    c->redo();
    Do_Com.push_back(c);
}
void    Gopro::faddwrkr(std::string depn,std::string s,
std::string f,
std::string m,
std::string func, int sal){
    c = new FaddWorker(depn,s,f,m,func,sal);
    c->set_company(&com);
    c->redo();
    Do_Com.push_back(c);
}

void    Gopro::delwrkr(std::string depn,std::string s){
    c = new DelWorker(depn,s);
    c->set_company(&com);
    c->redo();
    Do_Com.push_back(c);
}
void    Gopro::deldprtmnt(std::string name)
{
    c = new Deldep(name);
    c->set_company(&com);
    c->redo();
    Do_Com.push_back(c);
}
void    Gopro::chngdprtmntname(std::string name, std::string newname)
{
    c = new ChangeDepName(name, newname);
    c->set_company(&com);
    c->redo();
    Do_Com.push_back(c);
}

void    Gopro::editwrkr(std::string d,
    std::string s,
    std::string f,
    std::string m,
    std::string func,
    int sal) {
    c = new EditWorker(d,s,f,m,func,sal);
    c->set_company(&com);
    c->redo();
    Do_Com.push_back(c);
    }

void Gopro::UNDO() {
    if (Do_Com.size() == 0) {
        std::cerr << "There's nothing to undo" << std::endl;
    } else {
        c = Do_Com.back();
        Do_Com.pop_back();
        c->undo();
        No_Com.push_back(c);
    }
}
void Gopro::REDO() {
    if (No_Com.size() == 0) {
        std::cerr << "There's nothing to redo" << std::endl;
    } else {
        c = No_Com.back();
        No_Com.pop_back();
        c->redo();
        Do_Com.push_back(c);
    }
}

void    Gopro::print_gopro(){
        com.print_comp();
}
Gopro& Gopro::operator =(Gopro &other){
    c = other.c;
    return (*this);
}