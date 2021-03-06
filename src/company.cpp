//here is a map of all departments and commands 
//for execution with these departments through the above specified class of commands.
#include "../inc/company.h"

void    Company::add_worker(std::string depn,std::string s,
                                             std::string f,
                                             std::string m,
                                             std::string func, int sal){
    Worker process(s,f,m,func,sal);
    auto it = dpts.find(depn);
    if (it != dpts.end())
        it->second.addworker(process);
}
Company& Company::operator= (Company &other) {
        dpts = other.dpts;
        return (*this);
    }


void    Company::go_department(std::string name,Department &d){
    dpts[name] = d;
}
void    Company::set_comp(const Company &c){
    dpts = c.dpts;
}
void    Company::add_department(std::string name) {
    auto it = dpts.find(name);
    if (it == dpts.end())
    {
        Department  dpt(name);
        dpts[name] = dpt;
    }
    else
        std::logic_error("ERROR : department name:" + name + "already in");
}
void    Company::delete_department(std::string name){
    auto it = dpts.find(name);
    if (it != dpts.end())
        dpts.erase(it);
    else
        std::logic_error( "ERROR : department name:" + name + "NOT FOUND");   
}

void    Company::set_new_department_before_delete(std::string name, Department dep){
    dpts[name] = dep;
}

void    Company::edit_worker(std::string dpt, std::string swrk, std::string func, int salary){
    auto it = dpts.find(dpt);
    if (it != dpts.end())
    {
        it->second.edit_worker(swrk, func, salary);
    }
    else
        std::logic_error("Name:" + swrk + "NOT FOUND");
}


void    Company::change_department_name(std::string name, std::string newname){
    auto it = dpts.find(name);
    if (it != dpts.end())
    {
        auto process = dpts.find(newname);
        if (process == dpts.end())
        {
            Department newdep(it->second);
            newdep.change_department(newname);
            dpts[newname] = newdep;
            dpts.erase(it);
        }
        else 
            std::logic_error("Already has this dep name: " + newname) ; 
    }
    else 
        cout << "no";
    std::logic_error("Not Found dep name: " + name) ;  
}

void    Company::del_worker(std::string depn,std::string s){
    auto it = dpts.find(depn);
    if (it != dpts.end())
    {
        it->second.delworker(s);
    }
}
Worker   Company::find_worker(std::string depn,std::string s) {
    auto it = dpts.find(depn);
    Worker w;
    if (it != dpts.end())
    {
        w = it->second.workers[s];
    }
    else
        std::logic_error("not found department");
    return w;
}

Department Company::find_dpt (std::string name) {
        auto it = dpts.find(name);
        if (it != dpts.end()) {
            return it->second;
        } else {
            return Department();
        }
    }
void    Company::print_comp() {
    for (auto it = dpts.begin() ; it != dpts.end() ; it++)
    {
        it->second.print_department();
    }
}



