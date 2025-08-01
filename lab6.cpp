//#include<iostream>
//#include<cstring>
//using namespace std;
//
//bool isEmailChar(char ch) {
//    return (ch >= 'a' && ch <= 'z') ||  (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9') ||  ch == '.' || ch == '_' || ch == '@';
//}
//
//bool isDuplicate(char** arr, int count, char* email) {
//    for (int i = 0; i < count; i++) {
//        int same = 1;
//        int j = 0;
//        while (arr[i][j] != '\0' && email[j] != '\0') {
//            if (arr[i][j] != email[j]) {
//                same = 0;
//                break;
//            }
//            j++;
//        }
//        if (arr[i][j] != email[j]) 
//            same = 0;
//        if (same == 1) 
//            return true;
//    }
//    return false;
//}
//
//char** EmailExtractor(char** MsgArray, int rows, int& uniqueCount) {
//    char** TempEmailArray = new char* [rows * 2];  
//    uniqueCount = 0;
//
//    for (int i = 0; i < rows; i++) {
//        for (int j = 0; MsgArray[i][j] != '\0'; j++) {
//            if (MsgArray[i][j] == '@') {
//                int start = j;
//                while (start >= 0 && isEmailChar(MsgArray[i][start])) {
//                    start--;
//                }
//                start++;
//                int end = j;
//                while (MsgArray[i][end] != '\0' && isEmailChar(MsgArray[i][end])) {
//                    end++;
//                }
//
//                int len = end - start;
//                char* email = new char[len + 1];
//                int k = 0;
//                for (int x = start; x < end; x++) {
//                    email[k++] = MsgArray[i][x];
//                }
//                email[k] = '\0';
//
//                // Check for duplicate
//                if (!isDuplicate(TempEmailArray, uniqueCount, email)) {
//                    TempEmailArray[uniqueCount] = new char[len + 1];
//                    for (int z = 0; z <= len; z++) {
//                        TempEmailArray[uniqueCount][z] = email[z];
//                    }
//                    uniqueCount++;
//                }
//
//                delete[] email;
//
//                j = end - 1; 
//            }
//        }
//    }
//
//    // Create final exact size array
//    char** FinalEmailArray = new char* [uniqueCount];
//    for (int i = 0; i < uniqueCount; i++) {
//        int len = strlen(TempEmailArray[i]);
//        FinalEmailArray[i] = new char[len + 1];
//        for (int j = 0; j <= len; j++) {
//            FinalEmailArray[i][j] = TempEmailArray[i][j];
//        }
//        delete[] TempEmailArray[i];
//    }
//
//    delete[] TempEmailArray;
//    return FinalEmailArray;
//}
//
//int main() {
//    int Rows;
//    cout << "Enter the number of the messages in array ";
//    cin >> Rows;
//    cin.ignore();
//
//    char** MessagesArray = new char* [Rows];
//    for (int i = 0; i < Rows; i++) {
//        MessagesArray[i] = new char[200];
//    }
//
//    cout << "Enter the message "<<endl;
//    for (int i = 0; i < Rows; i++) {
//        cin.getline(MessagesArray[i], 200);
//    }
//
//    int uniqueEmailCount = 0;
//    char** EmailList = EmailExtractor(MessagesArray, Rows, uniqueEmailCount);
//
//    cout << "Distinct Email IDs "<<endl;
//    for (int i = 0; i < uniqueEmailCount; i++) {
//        cout << EmailList[i] << endl;
//    }
//
//    // delete memory
//    for (int i = 0; i < Rows; i++) {
//        delete[] MessagesArray[i];
//    }
//    delete[] MessagesArray;
//
//    for (int i = 0; i < uniqueEmailCount; i++) {
//        delete[] EmailList[i];
//    }
//    delete[] EmailList;
//
//    return 0;
//}
