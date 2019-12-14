// Copyright 2018 Your Name <your_email>

#include <iostream>
#include <boost/filesystem.hpp>
#include <map>
#include <vector>
#include <string>

#define DIRECTORY 3
#define COM_FILE 2
#define RIGHT_LENGTH 29

using boost::filesystem::path;

using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::stoi;

using boost::filesystem::directory_iterator;

class fsystem
{
public:

    bool is_digit(std::string verifiable){
        bool flag = true;
        for(int i = 0; i < 8; ++i)
        {
            if ((verifiable[i] < '0') || (verifiable[i] > '9'))
                flag = false;
        }
        return flag;
    }

    void print_first()
    {
        for (int it = 0; it < broker_map.size(); it++)
        {
            cout << broker_map[it][0] << " balance_" << broker_map[it][1] <<
            "_" << broker_map[it][2];
            cout << endl << it << endl;
        }
    }

    bool check_format(const path file_n)
    {
        bool flag = false;
        std::string file = file_n.c_str();

        if((file.length() == RIGHT_LENGTH) &&
        (file.substr(0,8) == "balance_") &&
        (is_digit(file.substr(8, 8))) &&
        (file[16] == '_') &&
        (is_digit(file.substr(17, 8))) &&
        (file.substr(25,4) == ".txt"))
            flag = true;
        return flag;
    }

    void create_account(path _path) {
        std::string __path = _path.filename().c_str();
        std::string __parent_name = _path.parent_path().filename().c_str();

        vector<std::string> tmp;
        tmp.push_back(__parent_name);
        tmp.push_back(__path.substr(8, 8));
        tmp.push_back(__path.substr(17, 8));
        broker_map.push_back(tmp);
    }

    void print_second()
    {
        for (int i = 0; i < clear_map.size(); ++i)
            cout << "broker:" << clear_map[i][0] <<
                 " account:" << clear_map[i][1] <<
                 " files:" << clear_map[i][2] <<
                 " lastdate:" << clear_map[i][3]
                 << endl;

    }

    void create_clear()
    {
        for (int it = 0; it < broker_map.size(); it++)
        {
            int j = 0;
            int flag = 0;
            for (; j < clear_map.size(); ++j)
            {

                if((broker_map[it][0] == clear_map[j][0]) &&
                (broker_map[it][1] == clear_map[j][1])) {
                    flag = 1;
                    int tmp = stoi(clear_map[j][2]);
                    tmp++;
                    clear_map[j][2] = std::to_string(tmp);
                    if (stoi(broker_map[it][2]) > stoi(clear_map[j][3])) {

                        clear_map[j][3] = broker_map[it][2];
                    }
                }
            }
            if (flag == 0) {
                vector<std::string> tmp;
                tmp.push_back(broker_map[it][0]);
                tmp.push_back(broker_map[it][1]);
                tmp.push_back("1");
                tmp.push_back(broker_map[it][2]);
                clear_map.push_back(tmp);
            }
        }
    }

    void start(path _input_dir)
    {
        parent_dir = _input_dir;
        engine(_input_dir);
        print_first();

        vector<vector<std::string>> a;
        create_clear();
        print_second();
    }


    void engine(path _input_dir)
    {
        for(directory_iterator p(_input_dir), end;p!=end;p++) {
            if(p->status().type() == DIRECTORY)
                engine(p->path());
            if (p->status().type() == COM_FILE) {
                if(check_format(p->path().filename()) == true)
                {
                    create_account(p->path());
                }
            }
        }
    }

    path parent_dir;
    vector<vector<std::string>> clear_map;
    vector<vector<std::string>> broker_map;
};

#endif // INCLUDE_HEADER_HPP_
