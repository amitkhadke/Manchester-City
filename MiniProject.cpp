/*  Instructions if running code with new files

1) whenever a new allApplicantsObj.bin file is going to set don't forget
   to truncet the count.txt file as well that is simply delete the file
   code will itself generate a fresh count file.
2) ...



    Modifications to be done
1)  sort the linked list while creationg it
2)  deleting admission function should delete the specified node and 
    again write the updated linked list using updateApplicantFile()
3) Student Module  
4) Revising certificates module is still not completed  
5) adding caste reservations criteria
6)  

6/4/22        5:20 pm
things done 

1) linked now gets sorted at the time of reading only
2) Function to write updated linked list every time has been created updateApplicantFile()
3) Operations are now carried out on linked list
4) login error is removed




*/

#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string.h>

using namespace std;

long id=2023000000;
int count=-1;
char countBuff[5];

class Student{
  long applicantID;
  char name[50];
  float cet, jee, boards10, boards12;
  int caste, religion;
  char address[100];
  int branch;
  long annualIncome;
  int c1, c2, c3, c4, c5, c6, c7, c8, c9;
  long fees_applicable, fees_paid;
  int admission_status;
  int cancelAdd;
     
                             /*
  0==>document required, status==>not attached         * c1==>10th marksheet
  -1==>document not required                         * c2==>12th marksheet
  1==>document required, status==>attached             * c3==>CET marksheet
                                                     * c4==>JEE marksheet
                                                     * c5==>caste certificate
                                                     * c6==>Nationality certificate
                                                     * c7==>school/college leaving certificate
                                                     * c8==>adhar card
                                                     * c9==>income certificate
                             */
  public:
  Student *nxt;
  Student *prv;  
  Student(){}
  void feed(){
    int c=-1;                    ///c==>Choice variable
    id++;
    applicantID=id;
    ///taking personal info
    cout<<"\nEnter your Name(FIRSTNAME MIDDLENAME SURNAME): ";
    cin.get(name, 50);
    cin.ignore();				//cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout<<"\nEnter your address: ";
    cin.get(address, 100);
    cin.ignore();				//cin.ignore(numeric_limits<streamsize>::max(), '\n');
    
    ///taking academic info
    cout<<"\nEnter your 10th boards percentage: ";
    cin>>boards10;
    cout<<"\nEnter your 12th boards percentage: ";
    cin>>boards12;
    
    k1:
    cout<<"\nHave you appeared for JEE, Press 1 if yes else press 0:  ";
    cin>>c;
    if(c==1 || c==0){
    }
    else{
      	cout<<"\nPlease choose from above mentioned options only.";
    	goto k1;
    }
    if(c==1){
      cout<<"\nEnter your JEE percentile: ";
      cin>>jee;
    }
    else{
      jee=0;
    }
    
    k2:
    cout<<"\nHave you appeared for CET, Press 1 if yes else press 0:  ";
    cin>>c;
    if(c==1 || c==0){
    }
    else{
      	cout<<"\nPlease choose from above mentioned options only.";
    	goto k2;
    }
    if(c==1){
      cout<<"\nEnter your CET percentile: ";
      cin>>cet;
    }
    else{
	    cet=0;
    }
    
    ///taking info about caste and relegion
    l1:
    cout<<"\nChoose your Caste:\n\t1.OPEN\n\t2.OBC\n\t3.SC\n\t4.ST\n\t5.NT";
    cout<<"\nEnter your option: ";
    cin>>caste;
    if(caste<1 && caste>5){
    	cout<<"\nPlease choose from above mentioned options only.";
    	goto l1;
    }
    
    l2:
    cout<<"\nChoose your Religion:\n\t1.HINDU\n\t2.MUSLIM\n\t3.CHRISTIAN\n\t4.BUDDHIST\n\t5.SIKH\n\t6.JAIN\n\t7.TRIBAL";
    cout<<"\nEnter your option: ";
    cin>>religion;
    if(religion<1 && religion>7){
    	cout<<"\nPlease choose from above mentioned options only.";
    	goto l2;
    }
    
    
    cout<<"\nEnter annual Income: ";
    cin>>annualIncome;
    
    l3:
    cout<<"\nChoose your Branch:\n\t1.CSE\n\t2.MECH\n\t3.ENTC\n\t4.CIVIL\n\t5.ELE\n\t6.BIOTECH\n\t7.ENV ";
    cout<<"\nEnter your choice: ";
    cin>>branch;
    if(branch<1 && branch>7){
      cout<<"\nPlease choose from above mentioned options only.";
      goto l3;
    }

    c1=0;
    c2=0;
    //c3
    if(cet==0){
    	c3=-1;
    }
    else{
    	c3=0;
    }
    //c4
    if(jee==0){
    	c4=-1;
    }
    else{
    	c4=0;
    }
    //c5
    if(caste==2){
    	fees_applicable=60536;
      c5=0;
    }
    else if(caste==3){
      fees_applicable=4060;
      c5=0;
    }
    else if(caste==4){
      fees_applicable=17012;
    }
    else if(caste==5){
      fees_applicable=17012;
    }
    else if(caste==1){
      fees_applicable=104060;
      c5=-1;
    }

    c6=0;
    c7=0;
    c8=0;
    if(annualIncome<120000){
    	c9=0;
    }
    else{
    	c9=-1;
    }
    admission_status=0;
    fees_paid=0;
    cancelAdd=0;
  }

  float getcet(){
  	return cet;
  }
  
  int getbranch(){
  	return branch;
  }
  
  void disp(){
    //cout<<"\nYOUR APPLICANT ID IS "<<applicantID<<" PLEASE MAKE NOTE OF IT"<<endl;
    cout<<"Name: "<<name<<endl;
    cout<<"Address: "<<address<<endl;
    cout<<"10th: "<<boards10<<endl;
    cout<<"12th: "<<boards12<<endl;
    cout<<"cet: "<<cet<<endl;
    cout<<"jee: "<<jee<<endl;
    ///printing caste 
    if(caste==2){
    	cout<<"\nCaste: OBC"<<endl;
    }
    else if(caste==3){
      cout<<"\nCaste: SC"<<endl;
    }
    else if(caste==4){
      cout<<"\nCaste: ST"<<endl;
    }
    else if(caste==5){
      cout<<"\nCaste: NT"<<endl;
    }
    else if(caste==1){
      cout<<"\nCaste: OPEN"<<endl;
    }    

    ///printing religion
    if(religion==1){
      cout<<"Relgion: HINDU"<<endl;
    }
    else if(religion==2){
      cout<<"Relgion: MUSLIM"<<endl;
    }
    else if(religion==3){
      cout<<"Relgion: CHRISTIAN"<<endl;
    }
    else if(religion==4){
      cout<<"Relgion: BUDDHIST"<<endl;
    }
    else if(religion==5){
      cout<<"Relgion: SIKH"<<endl;
    }
    else if(religion==6){
      cout<<"Relgion: JAIN"<<endl;
    }        
    else if(religion==7){
      cout<<"Relgion: TRIBAL"<<endl;
    }

    cout<<"Annual Income: "<<annualIncome<<endl;
    //printing branch
    if(branch==1){
      cout<<"Branch: CSE"<<endl;
    }
    else if(branch==2){
      cout<<"Branch: MECH"<<endl;
    }
    else if(branch==3){
      cout<<"Branch: ENTC"<<endl;
    }
    else if(branch==4){
      cout<<"Branch: CIVIL"<<endl;
    }
    else if(branch==5){
      cout<<"Branch: ELE"<<endl;
    }
    else if(branch==6){
      cout<<"Branch: BIOTECH"<<endl;
    }
    else if(branch==7){
      cout<<"Branch: ENV"<<endl;
    }

    cout<<"10th marksheet: "<<getStatus(c1)<<endl;
    cout<<"12th marksheet: "<<getStatus(c2)<<endl;
    cout<<"CET: "<<getStatus(c3)<<endl;
    cout<<"JEE: "<<getStatus(c4)<<endl;
    cout<<"caste: "<<getStatus(c5)<<endl;
    cout<<"Nationality: "<<getStatus(c6)<<endl;
    cout<<"school/college leaving certificate:: "<<getStatus(c7)<<endl;
    cout<<"adhar card: "<<getStatus(c8)<<endl;
    cout<<"Income Certificate: "<<getStatus(c9)<<endl;
    cout<<"Fees Applicable: "<<fees_applicable<<endl;
    cout<<"Fees Paid: "<<fees_paid<<endl;
    ///Printing Admission Status
    if(admission_status==0){
      cout<<"\nApplication Pending";
      cout<<"\nAttach all the required Documents and pay the fees";
    }
    else if(admission_status==1){
      cout<<"\nApplication considered.\nCongratulations !!! Your Admission has been Confirmed";
    }
    else if(admission_status==-1){
      cout<<"\nAdmission Canceled";
    }
  }
  
  void wrtToBranchFile(const char *filename){
    	ofstream fout1;
      fout1.open(filename, ios::app);
    	if(!fout1.is_open()){
      		cout<<"ERROR";
    	}
    	fout1<<applicantID<<"\t\t\t\t"<<cet<<"\t\t\t\t"<<name<<endl;
    	fout1.close(); 
  }

  string getStatus(int i){
    if(i==-1){
      return "\nCertificate Not required";
    }
    else if(i==0){
      return "\nCerticficate required\nStatus: NOT ATTACHED";
    }
    else if(i==1){
      return "\nCertifiate required\nStatus: ATTACHED";
    }
  }

  void updateStatus(int i){
    int c;
    if(i=-1){
      cout<<"\nDocument not required.";
    }
    else{
      l:
      cout<<"\nIf document is attached, press 1 to update it's status to 'ATTACHED',else if not attached press 0: ";
      cout<<"\nEnter your choice: ";
      cin>>c;
      switch(c){
        case 0:
          i=0;
        break;
        case 1:
          i=1;
        break;
        default:
          cout<<"\nChoose from above mentioned options only: ";
          goto l;
        break;
      }
    }
  }

  void edit(){
    int choice;
    int c, choice1, choice2, choice3;
    cout<<applicantID<<endl;
    cout<<name<<endl;
    l1:
    cout<<"Choose your Option:\n\t1.Revise Certificates\n\t2.Change/check fee status\n\t3.exit";
    cin>>c;
    switch(c){
      case 1:
      do{
        n1:
        cout<<"\nChoose for which certificate you want to update the status: ";
        cout<<"\n\t1.10th marksheet\n\t2.12th marksheet\n\t3.CET marksheet\n\t4.JEE marksheet\n\t5.Caste Certificate"
              "\n\t6.Nationality Certificate\n\t7.College leaving Certificate\n\t8.Aadhar Card\n\t9.Income certificate";
        cin>>choice;
        switch(choice){
        case 1:
          updateStatus(c1);
        break;
        case 2:
          updateStatus(c2);
        break;
        case 3:
          updateStatus(c3);
        break;
        case 4:
          updateStatus(c4);
        break;
        case 5:
          updateStatus(c5);
        break;  
        case 6:
          updateStatus(c6);
        break;
        case 7:
          updateStatus(c7);
        break;
        case 8:
          updateStatus(c8);
        break;
        case 9:
          updateStatus(c9);
        break;
        default:
          cout<<"\nChoose from above mentioned options only";
          goto n1;
        break;
        }
        cout<<"\nIf you want to exit press 1, else press 0: ";
        cin>>choice2;
      }while(choice==0);
      break;
      case 2:
        updateFeeStatus();
      break;
      case 3:
        return;
      break;
      default:
        cout<<"\nChoose from above mentioned options only: ";
        goto l1;
      break;
    }
    
    m1:
    cout<<"\nDo you want to confirm this admission ?\nif yes press 1 else press 0: ";
    cin>>choice1;
    switch(choice1){
      case 0:
        return;
      break;
      case 1:
        admission_status=1;
        cout<<"\nAdmission Confirmed";
      break;
      default:
        cout<<"\nChoose from above mentiones options only: ";
        goto m1;
      break;
    }
  }



  void updateFeeStatus(){
    cout<<"\nFees applicable is: "<<fees_applicable;
    cout<<"\nEnter the amount paid: ";
    cin>>fees_paid;
  }

  friend void createAndWriteObj();
  friend void readAndCreateLL();
  //friend void bubbleSort();
  friend void displayLL();
  //friend void reverse();
  friend void sortBranch(int);
  friend void adminModule();
  friend void verifyAndEdit();
  friend void cancelAdmission();
  friend void updateApplicantFile();
};

Student  *start=NULL, *temp=NULL;
Student  *temp1=NULL;

void createAndWriteObj(){
  Student *ptr=new Student;
  ptr->feed();
  ofstream fout1;
  fout1.open("allApplicantsObj.bin", ios::binary | ios::app);
  if(!fout1.is_open()){
    cout<<"ERROR: line 222";
  }
  fout1.write((char*)ptr, sizeof(Student));
  fout1.close();
  count++;
  ofstream fout;
  fout.open("count.txt", ios::out);
  if(!fout.is_open()){
    cout<<"\nERROR: can not write count to the file";
  }
  fout<<count;
  fout.close();
}

void readAndCreateLL(){
  int i=0, nodeIndex=0;                  ///loop variable
  //cout<<"\nline 423";
  ifstream fin3;
  fin3.open("count.txt", ios::in);
  if(!fin3.is_open()){
    cout<<"\nERROR: Error while opening a file to read the count";
  }
  fin3.read(countBuff, 5*sizeof(char));
  fin3.close();
  count=atoi(countBuff);
  //cout<<"\nCount is: "<<count;
  ///creating linked list from read objects
  start=NULL;
  ifstream fin2;
  fin2.open("allApplicantsObj.bin", ios::binary | ios::in);
  if(!fin2.is_open()){
    cout<<"ERROR: readAndWriteLL()";
  }
  //cout<<"\nline 439";
  while(i<=count){
    //cout<<"\ni: "<<i;
    nodeIndex=1;
    Student *sptr=new Student;
    fin2.read((char*)sptr, sizeof(Student));
    sptr->nxt=NULL;
    sptr->prv=NULL;
    if(start==NULL){
      start=sptr;
    }
    else{
      temp=start;
      while(temp!=NULL){      ///if error occurs try: while(temp-nxt!=NULL){}
        if(nodeIndex==1){
          if((sptr->getcet())<(temp->getcet())){
            start=sptr;
            sptr->nxt=temp;
            temp->prv=sptr;
            /*temp->nxt=sptr;
            sptr->prv=temp;
            temp=sptr;
            sptr->nxt=NULL;*/
            //last=sptr;
            temp=temp->nxt;
          }
          nodeIndex++;
        }
        else{
          if((sptr->getcet())>=(temp->getcet())){
            temp1=temp->nxt;
            sptr->nxt=temp1;
            temp1->prv=sptr;
            temp->nxt=sptr;
            sptr->prv=temp;
            temp=temp->nxt;
          }
          else{
            temp1=temp->prv;
            temp1->nxt=sptr;
            sptr->prv=temp1;
            sptr->nxt=temp;
            temp->prv=sptr;
            temp=temp->nxt;
          }
          nodeIndex++;
        }
      }
      /*if(first==1){
        if((sptr->getcet())>(current->getcet())){
          current->nxt=sptr;
          sptr->prv=current;
          current=sptr;
          sptr->nxt=NULL;
          last=sptr;
        }
        else{
          start=sptr;
          sptr->nxt=current;
          current->prv=sptr;
          current->nxt=NULL;
          sptr->prv=NULL;
          last=current;
        }
      }
      else{
        temp=start;
        while()      
      }*/
    }

    if(fin2.eof()){
      break;
    }
    i++;
  }
  fin2.close();
  /*cout<<"\nprinting";
  temp=start;
  cout<<"\nThe applicatID's are: ";
  while(temp!=NULL){
    cout<<temp->getcet()<<", ";
    temp=temp->nxt;
  }*/  
}

void updateApplicantFile(){
  temp=start;
  ofstream fout;
  fout.open("allApplicantsObj.bin", ios::trunc);
  fout.close();

  fout.open("allApplicantsObj.bin", ios::binary | ios::out);
  if(!fout.is_open()){
    cout<<"\nERROR : writeLL()";
  }
  while(temp!=NULL){
    fout.write((char*)temp, sizeof(Student));
    temp=temp->nxt;
  }
  fout.close();
}

void displayLL(){
  temp=start;
  cout<<"\nDisplaying applicantID: ";
  while(temp!=NULL){
  	cout<<temp->applicantID<<", ";
  	temp=temp->nxt;
  }
}

void sortBranch(int branchID){
  Student *ptr;
  ptr=start;
  if(branchID==1){
    while(ptr!=NULL){
      if(branchID==ptr->getbranch()){
        ptr->wrtToBranchFile("CSE.txt");
      }
      ptr=ptr->nxt;
    }
  }
  else if(branchID==2){
    while(ptr!=NULL){
      if(branchID==ptr->getbranch()){
        ptr->wrtToBranchFile("MECH.txt");
      }
      ptr=ptr->nxt;
    }
  }
  else if(branchID==3){
    while(ptr!=NULL){
      if(branchID==ptr->getbranch()){
        ptr->wrtToBranchFile("ENTC.txt");
      }
      ptr=ptr->nxt;
    } 
  }
  else if(branchID==4){
    while(ptr!=NULL){
      if(branchID==ptr->getbranch()){
        ptr->wrtToBranchFile("CIVIL.txt");
      }
      ptr=ptr->nxt;
    }
  }
  else if(branchID==5){
    while(ptr!=NULL){
      if(branchID==ptr->getbranch()){
        ptr->wrtToBranchFile("ELE.txt");
      }
      ptr=ptr->nxt;
    }
  }
  else if(branchID==6){
    while(ptr!=NULL){
      if(branchID==ptr->getbranch()){
        ptr->wrtToBranchFile("BIOTECH.txt");
      }
      ptr=ptr->nxt;
    }
  }
  else if(branchID==7){
    while(ptr!=NULL){
      if(branchID==ptr->getbranch()){
        ptr->wrtToBranchFile("ENV.txt");
      }
      ptr=ptr->nxt;
    }    
  }
}

/*void reverse(){
  temp=start;
  while(temp!=NULL){
    temp=temp->nxt;
    temp->nxt=temp->prv;
    temp->prv=temp;
    temp=temp;
  }
  temp=start;
  start=
  last=temp;

  cout<<"\nAfter reverse: ";
  temp=start;
  cout<<"\nThe applicatID's are: ";
  while(temp!=NULL){
    cout<<temp->getcet()<<", ";
    temp=temp->nxt;
  } 
}*/

/*void bubbleSort(){
  

  ///bubblesort module starts

  ////bubblesort module ends  
    
  temp=start;
  cout<<"\nDisplaying applicantID: ";
  while(temp!=NULL){
  	cout<<temp->applicantID<<", ";
  	temp=temp->nxt;
  } 
}*/
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
class Login{
  char userName[10];
  char password[10];

  public:
    Login(){}
    void feedAcc(){
      cout<<"\nThe username and password should be of maximum 10 characters";
      cout<<"\nEnter Username: ";
      cin.get(userName, 10);
      cin.ignore();
      cout<<"\nEnter Password: ";
      cin.get(password, 10);
      cin.ignore();
      return;
    }
    friend int login(const char*);
    friend int signup(const char*);
};

int signup(const char *filename){
  Login *ptr=new Login;
  ptr->feedAcc();
  ofstream fout;
  fout.open(filename, ios::binary | ios::app);
  if(!fout.is_open()){
    cout<<"\nERROR : error while opening file in signup()";
  }
  fout.write((char*)ptr, sizeof(Login));
  fout.close();
  return 0;
}

int login(const char *filename){
  l1:
  char uName[10];
  char pass[10];
  Login *sptr=new Login;
  ifstream fin;
  fin.open(filename, ios::binary | ios::in);
  if(!fin.is_open()){
    cout<<"\nUsername is not present. Please signup first.";
    signup(filename);
  }
  cout<<"\nEnter Username: ";
  cin.get(uName, 10);
  cin.ignore();
  while(!fin.eof()){
    fin.read((char*)sptr, sizeof(Login));
    int uResult=strcmp(uName, sptr->userName);
    if(fin.eof()){
        cout<<"\nUsername is not present. Please signup first.";
        fin.close();
        signup(filename);
    }
    if(uResult==0){
      cout<<"\nEnter Password: ";
      cin.get(pass, 10);
      cin.ignore();
      int pResult=strcmp(pass, sptr->password);
      if(pResult==0){
        cout<<"\nLogged in successfully";
        return 1;
      }
      else{
        cout<<"\nWrong password";
        login(filename);  
      }
    }
  }
}

int homepg(){
  int c, c1, ad, stu;                          ////choice variable
  cout<<"\t\t\t\t\t"<<"\nWELCOME TO KIT's COLLEGE OF ENGINEERING KOLHAPUR"<<"\t\t\t\t\t"<<endl;
  cout<<"\nChoose your option:\n\t1.Login as Student\n\t2.Login as Admin\n\t3.exit.";
  cout<<"\nEnter your choice: ";
  cin>>c;
  switch(c){
    case 1:  
      cout<<"\nChoose your option:\n\t1.Signup\n\t2.login ";
      cout<<"\nif you are not registered please signup first";
      cout<<"\nEnter your choice: ";
      cin>>c1;
      if(c1==1){
        cin.ignore();
        signup("stuLoginDetails.bin");
      }
      else if(c1==2){
        cin.ignore();
        login("stuLoginDetails.bin");
      }
      break; 
    case 2:
      cout<<"\nChoose your option:\n\t1.Signup\n\t2.login ";
      cout<<"\nif you are not registered please signup first";
      cout<<"\nEnter your choice: ";
      cin>>c1;
      if(c1==1){
        cin.ignore();
        signup("adminLoginDetails.bin");
      }
      else if(c1==2){
        cin.ignore();
        login("adminLoginDetails.bin");
      }
      break;
    case 3:
      return 0;
      break;
  }
  return c;
}

class Round:public Student{
  char dates[15];
  char round[2];
  char workingHours[10];
  public:
    Round(){}
    void setDates(){
      cout<<"\nSet the duration of admission process : ";
      cin.get(dates, 15);
      cin.ignore();
    }

    void setWorkingHours(){
      cout<<"\nSet the working hours: ";
      cin.get(workingHours, 10);
      cin.ignore();
    }
    friend int homepg();
};

///forward declaration of functions
void verifyAndEdit();
void cancelAdmission();

void adminModule(){
  //long appID;
  int c;
  cout<<"\nChoose your options:\n\t1.Set Dates and working Hours for admission process"
          "\n\t2.verify and edit\n\t3.Cancel admission\n\t4.Return to Home page";
  cout<<"\nEnter your choice: ";
  cin>>c;
  switch(c){
    case 1:
      
    break;
    case 2:
      verifyAndEdit();
    break;
    case 3:
      cancelAdmission();
    break;
    case 4:
      homepg();
    break;  
  }
}

void cancelAdmission(){
  m1:
  long appID;  
  /*ifstream fin;
  fin.open("allAplicantsObj.bin", ios::binary | ios::in);
  if(!fin.is_open()){
    cout<<"ERROR :line 722";
  }*/
  cout<<"Enter applicant ID you want to Remove: ";
  cin>>appID;
  Student *ptr=start;
  /*while(!fin.eof()){
    fin.read((char*)ptr, sizeof(Student));
    if(ptr->applicantID==appID){
      ptr->disp();
      break;
    }
    if(fin.eof()){
      cout<<"\nWrong applicant ID enterd or applicant ID does not exists";
      fin.close();
      goto m1;
    }
  }*/
  while(ptr!=NULL){
    if(ptr->applicantID==appID){
      ptr->disp();
      break;
    }
    else{
      cout<<"\nWrong applicant ID entered or applicant ID does not exists";    
      goto m1;
    }
    ptr=ptr->nxt;
  }
  ptr->admission_status=-1;
  cout<<"\nAdmission Canceled";
}

void verifyAndEdit(){
  m1:
  long appID;
  int c, c1, c2;
  cout<<"\nEnter the applicant ID you want to check: ";
  cin>>appID;
  //ifstream fin;
  //fin.open("allAplicantsObj.bin", ios::binary | ios::in);
  Student *ptr=start;
  /*while(!fin.eof()){
    fin.read((char*)ptr, sizeof(Student));
    if(ptr->applicantID==appID){
      ptr->disp();
      break;
    }
    if(fin.eof()){
      cout<<"\nWrong applicant ID enterd or applicant ID does not exists";
      fin.close();
      goto m1;
    }
  }*/
  while(ptr!=NULL){
    if(ptr->applicantID==appID){
      ptr->disp();
      break;
    }
    else{
      cout<<"\nWrong applicant ID entered or applicant ID does not exists";
      goto m1;
    }
    ptr=ptr->nxt;
  }
  ///Confirm or edit module starts here
  k1:
  cout<<"\nChoose your option:\n\t1.Confirm admission\n\n\t2.Edit/Update the certificate status";
  cout<<"\nEnter your option: ";
  cin>>c;
  switch(c){
    case 1:
      l1:
      cout<<"\nTo confirm admission Press 1, else Press 0: ";
      cin>>c1;
      switch(c1){
        case 0:
          ptr->admission_status=0;
          cout<<"\nAttach all the required Documents and pay the fees";
          l2:
          cout<<"\nDo you want to move to the next Student profile ?\nIf yes press 1, else press 0: ";
          cin>>c2;
          switch(c2){
            case 0:
              adminModule();
            break;
            case 1:
              verifyAndEdit();
            break;
            default:
              cout<<"\nChoose from above mentioned options only: ";
              goto l2;
            break;
          }
        break;
        case 1:
          ptr->admission_status=1;
          cout<<"\nAdmission Confirmed";
          l3:
          cout<<"\nDo you want to move to the next Student profile ?\nIf yes press 1, else press 0: ";
          cin>>c2;
          switch(c2){
            case 0:
              adminModule();
            break;
            case 1:
              verifyAndEdit();
            break;
            default:
              cout<<"\nChoose from above mentioned options only: ";
              goto l3;
            break;
          }
        break;
        default:
          cout<<"\nChoose from above mentioned options only: ";
          goto l1;
        break;
      }         ////case 1 ends here
    break;
    ///edit/update profile
    case 2:
      ptr->edit();
      l4:
      cout<<"Do you want to move to next Student profile ?\nIf yes press 1, else press 0: ";\
      cin>>c2;
      switch(c2){
        case 0:
          adminModule();
        break;
        case 1:
          verifyAndEdit();
        break;
        default:
          cout<<"\nChoose from above mentioned options only: ";
          goto l4;
        break;
      }
    break;
    default:
      cout<<"\nChosse from above mentioned options only: ";
      goto k1;
    break;
  }
}

int main(){
  int dec;
  /*ofstream file;
  file.open("allApplicantsObj.bin", ios::binary | ios::trunc);
  file.close();*/
  /*createAndWriteObj();
  cin.ignore();
  createAndWriteObj();
  cin.ignore();*/
  /*for(int i=0; i<2; i++){
    createAndWriteObj();
    cin.ignore();
  }*/

  readAndCreateLL();
  //reverse();
  for(int i=0; i<8; i++){
    sortBranch(i);
  }
  dec=homepg();
  if(dec==1){

  }
  else if(dec==2){
    adminModule();
  }
  return 0;
}
