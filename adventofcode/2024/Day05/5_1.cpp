#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

std::vector<int> split_line(std::string line, char deli)
{
    int num = 0;
    std::vector<int> tokens;
    for(int i = 0; i < line.size(); i++){
        if(line[i] == deli){
            tokens.push_back(num);
            num = 0;
        } else
            num = num * 10 + (line[i] - '0');
    }
    tokens.push_back(num);
    return tokens;
}
bool search_rule(std::unordered_map<int, std::vector<int>> umap, int ele1, int ele2)
{
    if(umap.find(ele2) != umap.end()){
        std::vector<int>& temp = umap[ele2];
        for(int i = 0; i < temp.size(); i++){
            if(temp[i] == ele1)
                return false;
        }
    }
    return true;
}
int main()
{
    std::ifstream inp_file;
    inp_file.open("input.txt");
    int res = 0;
    int res2 = 0;
    if(inp_file.is_open()){
        std::unordered_map<int, std::vector<int>> umap;
        std::string line;
        bool rules_over = false;
        while(std::getline(inp_file, line)){
            if(line.size() == 0){
                rules_over = true;
                continue;
            }
            if(!rules_over){
                std::vector<int> tokens = split_line(line, '|');
                if(umap.find(tokens[0]) == umap.end())
                    umap.emplace(tokens[0], std::vector<int>{tokens[1]});
                else
                    umap[tokens[0]].push_back(tokens[1]);
            } else {
                std::vector<int> update = split_line(line, ',');
                int n = update.size();

                //part 1
                int i;
                for(i = 0; i < n; i++){
                    int j;
                    for(j = i + 1; j < n; j++){
                        if(!search_rule(umap, update[i], update[j])){
                            break;
                        }
                    }
                    if(j != n)
                        break;
                }
                if(i == n){
                    int m = (n - 1) / 2;
                    res += update[m];
                }

                //part 2
                bool flag = false;
                for(i = 0; i < n; i++){
                    for(int j = i + 1; j < n; j++){
                        if(!search_rule(umap, update[i], update[j])){
                            flag = true;
                            std::swap(update[i], update[j]);
                        }
                    }
                }
                if(flag){
                    int m = (n - 1) / 2;
                    res2 += update[m];
                }
            }
        }
    }
    inp_file.close();
    std::cout << res << std::endl;
    std::cout << res2 << std::endl;
    return 0;
}
