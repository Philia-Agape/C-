#include<bits/stdc++.h>
#include<string>
#include<stack>
//#include<string>
//using namespace std;

//void Core::parseCSV(){
void parse_rank(std::vector<std::vector<std::string>>& parsed_rank){
    std::ifstream data("Downloads/world-skill-standings_hs.csv");
    std::string line;
    std::string pre_line;
    int index = 0, stack = 0;
    while(std::getline(data,line)){
        std::stringstream lineStream(line);
        std::string cell;
        std::vector<std::string> parsedRow;
        while(std::getline(lineStream,cell,',')){
            //15 column, NOT ALWAYS the 11 column is the Team Number
            //HERE WE CHANGE THE J-COLUMN DATA TO 114514 TO HELP IDENTIFY THE CELL DATA
            //if (index % 15 == 10) parsedRow.push_back(cell);
            if(pre_line == "-1" || stack > 0){
               if(pre_line == "-1") stack = 4; 
               parsedRow.push_back(cell);
               stack--;
            }   
            if (pre_line == "114514"  && cell != "0" ) parsedRow.push_back(cell);
            pre_line = cell;
        }
        index++;
        parsed_rank.push_back(parsedRow);
        if(index >= 160) { break;}
    }

    //check size
    printf("Rank size: %lu , %lu \n", parsed_rank.size(), parsed_rank[0].size());
    index = 0;
    /*
    for (auto& vector_string : parsed_rank){
       for (auto& ss: vector_string){
          //printf("%s ", ss);
          std::cout << ss << "\n";
       }
       printf("\n");
       index++;
       if (index >= 10) break;
    }
    
    //index = 0;
    
    std::ofstream output_data("Downloads/vinci_report.csv");
    for (auto& vector_string: parsed_rank){
       for (auto& ss: vector_string){
          //printf("%s ", ss);
          //std::cout << ss << "\n";
          output_data << ss << "\n";
       }
       //printf("\n");
       //index++;
       //if (index >= 10) break;
    }
    */
    return;
}

void parse_division(std::vector<std::vector<std::string>>& parsed_divi){
   std::ifstream data("Downloads/IQ_DIVISION_6900A - Sheet1.csv");
   std::string line;
   std::string pre_line;
   int index = 0;
   
   while(std::getline(data,line)){
      std::stringstream lineStream(line);
      std::string cell;
      std::vector<std::string> parsedRow;
      
      while(std::getline(lineStream, cell, ',')){
         /*
         if (pre_line == "Middle" && cell == "School") continue;
         if (pre_line == "Middle") parsedRow.push_back(cell);
         parsedRow.push_back(cell);
         */
         if (cell[0] - '0' <= 9 && cell[0] - '0' >= 0){
            parsedRow.push_back(cell);
            //std::cout << cell << "\n";
         }
         pre_line = cell;
      }
      parsed_divi.push_back(parsedRow);  
      //std::cout<< parsed_divi[0][0];
   }
   
   printf("Rank size: %lu , %lu \n", parsed_divi.size(), parsed_divi[0].size());
   //std::string out_put = parsed_divi[1][0];
   //std::cout << parsed_divi[1][0] << "\n";
   
/*   
   for (auto& vector_string : parsed_divi){
       for (std::string& ss: vector_string){
          //printf("%s ", ss);
          std::cout << ss << "\n";
       }
       printf("\n");
       index++;
       if (index >= 10) break;
   }
*/   
   return;
}

void pick_strong_opponent(std::vector<std::vector<std::string>>& parsed_rank, std::vector<std::vector<std::string>>& parsed_divi){
   
   for(const auto& row: parsed_rank){
     for(const auto& row2: parsed_divi){
       for(const auto& divi_str: row2){
         std::stack<std::string> out_put {};
         for(const auto& rank_str: row){
            out_put.push(rank_str);
                if (rank_str == divi_str){
                   //std::cout << rank_str << "\n"; 
                   //std::cout << rank2[0] << "\n";
                   while(!out_put.empty()){
                      std::cout << out_put.top() << " ";
                      switch(out_put.size()){
                         case 5:
                            std::cout << "(";
                           break;
                         case 4: 
                           std::cout << " + ";
                           break;
                         case 3:
                           std::cout << " = ";
                           break;
                         case 2:
                           std::cout << " Rank: ";
                           break;  
                         case 1:
                           std::cout << ")";
                           break;
                                
                      }
                      out_put.pop();
                   }
                   std::cout << "\n";
                   break; 
                }
            }         
         }
     }
   }  
   
   /*
   for(const auto& row: parsed_rank){
     for(const auto& rank_str: row){
         for(const auto& row2: parsed_divi){
            std::stack<std::string> out_put {};
            for(const auto& divi_str: row2){
                out_put.push(divi_str);
                if (divi_str == "842T"){
                   //std::cout << rank_str << "\n"; 
                   //std::cout << rank2[0] << "\n";
                   std::cout<< "SIZE " << out_put.size() << "\n";
                   while(!out_put.empty()){
                      std::cout << out_put.top() << "\n";
                      out_put.pop();
                   }
                   break; 
                }
            }         
         }
     }
   }    
   //std::cout<< parsed_rank[0][0] << "\n";
   //printf("%s\n", parsed_rank[3][0]);
   //printf("%s\n", parsed_divi[0][0]);
   
   for(int i=0; i<parsed_rank.size(); ++i){
      for(int j=0; j<parsed_divi.size(); ++j){
         if (parsed_rank[i][0] == parsed_divi[j][0]){
            std::cout<< parsed_rank[i][0] << "\n";
         }   
      }
   }
   */
   return;
}

int main(){
   //Init
   //std::vector<std::vector<std::string>> parsed_rank (100, std::vector<std::string> (5));
   //std::vector<std::vector<std::string>> parsed_divi (100, std::vector<std::string> (5));
   std::vector<std::vector<std::string>> parsed_rank;
   std::vector<std::vector<std::string>> parsed_divi;
   //std::cout << parsed_rank[0][0] << "yes\n";
   //Read from rank and division, find strong opponent
   parse_rank(parsed_rank);
   parse_division(parsed_divi);
   pick_strong_opponent(parsed_rank, parsed_divi);
   
   /* std::stoi
   std::string ss1 = "2023-02-18 02:31:10";
   std::string ss2 = "201";
   //printf("ss1 = %d, ss2 = %d\n", (std::stoi)(ss1), (std::stoi)(ss2));
   std::cout << ss1.substr(0,5) << "\n";
   */
   return 0;
}

