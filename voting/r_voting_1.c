#include<stdio.h>
#include<stdlib.h>

struct account {
    char username[50]; 
    char password[50];
};

struct polls {
    char pollName[50]; 
    char pollNum[50];
};

void read_file(struct account *);
void CreateUser();
void CreatePolls();
void Quit();
void Nominate();
void Changepassword(struct account *, char *);
void DisplayPollResults();

void main()
{
	struct account *accounts[100];
	char *u_str[50];
	char *p_str[50];
	struct account item[100];
	int choice;
	char *username[50];
	printf("\n--------------------------Login Screen--------------------------\n\n");
	printf("Username:");
	scanf("%s", &u_str);
	printf("USername read successfully %s\n", u_str);
	printf("password:");
	scanf("%s", &p_str);
	printf("Password read successfully %s \n", p_str);
	read_file(*accounts);
	printf("File read successfully\n");
	
	for(int i = 0; i <= sizeof(item); i++){
		if(*u_str == "admin" && *p_str == "admin"){
			printf("--------------------------Admin Screen---------------------------");
			printf("1. Create Users");
			printf("2. Create Polls");
			printf("3. Calculate Poll Results");
			printf("0. Quit");
			
			switch (choice)
			{
				case 1:
				CreateUser();
				break;

				case 2:
				CreatePolls();
				break;
				
				case 3:
				//CalculatePollresults();
				break;
				
				case 0:
				Quit();
				break;
    
				default:
				printf("Wrong Input");
			}
		}
		else if(accounts[i]->username == *u_str && accounts[i]->password == *p_str){
			printf("--------------------------User Screen---------------------------");
			printf("1. Nominate");
			printf("2. Vote");
			printf("3. Display poll results");
			printf("4. Change password");
			printf("0. Quit");

			*username == *u_str;
			switch (choice)
			{
				case 1:
				Nominate();
				break;

				case 2:
				//Vote();
				break;
				
				case 3:
				DisplayPollResults();
				break;
				
				case 4:
				Changepassword(*accounts, *username);
				break;
				
				case 0:
				Quit();
				break;
    
				default:
				printf("Wrong Input");
			}
		}
		else {
			printf("Invalid User or password");
			break;
		}
	}
	
}

void read_file(struct account accounts[])
{
    FILE* fp;
    int i=0;   // count how many lines are in the file
    int c;
    
    printf("Initiating file read from read_file \n");

    fp=fopen("users.txt", "r");

    printf("Cal num of lines \n");

    while(!feof(fp)) {
        c=fgetc(fp);
	printf("%d\t",c);
        if(c=='\n')
            ++i;
    }

    printf("%d\n", i);

    int j=0;

    rewind(fp);  // Line I added // read each line and put into accounts
	printf("Reading user values from line %d \n", j);

    while((fscanf(fp, "%*s,%*s", accounts[j].username, accounts[j].password))>0){
	printf("REading file details\n");
	printf("%S\t %s\t\n", accounts[j].username, accounts[j].password);
	printf("User details acquired from the file\n");
        ++j;
	--i;
    }
    fclose(fp);
    printf("read file func comp");
}

void CreateUser()
{
	char user[51];
	FILE *fptr;
	char status;
	printf("Enter Username:");
	scanf("%s",&user);
	fptr = fopen("users.txt", "a");
	gets(user);
	fprintf(fptr, "%s,%s", user, user);
	fclose(fptr);
	printf("Do you want to add more users (y/n)?");
	scanf("%c",&status);
	if(status == 'y'){
		CreateUser();
	}
}

void CreatePolls()
{
	char PollName[10];
	char PollDescription[50];
	int WardNo;
	char PollDate[10];
	FILE *fptr;
	char status;
	
	printf("Poll Name:");
	scanf("%s", PollName);
	printf("Poll Description:");
	scanf("%s", PollDescription);
	printf("Poll Date (in DD/MM/YY format):");
	scanf("%s", PollDate);
	printf("Ward No.:");
	scanf("%d", &WardNo);
	
	fptr = fopen("polls.txt", "a");
	//gets(PollName);
	fprintf(fptr, "%s", PollName);
	//gets(PollDescription);
	fprintf(fptr, "%s", PollDescription);
	//gets(PollDate);
	fprintf(fptr, "%s", PollDate);
	//gets(WardNo);
	fprintf(fptr, "%d", WardNo);
	fclose(fptr);
	
	printf("Do you want to add more users (y/n)?");
	scanf("%c", &status);
	if(status == 'y'){
		CreatePolls();
	}
}

void Quit()
{
	exit(0);
}

void Nominate(struct polls pollS[])
{
	FILE *fp;
	FILE *fptr;
    int i=0;   // count how many lines are in the file
    int c;
    fp=fopen("users.txt", "r");
    while(!feof(fp)) {
        c=fgetc(fp);
        if(c=='\n')
            ++i;
    }
    int j=0;
    rewind(fp);  // Line I added
        // read each line and put into accounts
	fptr = fopen("candidates.txt", "a");
    while(j!=i-1) {
        fscanf(fp, "%s %s", pollS[j].pollName, pollS[j].pollNum);
        ++j;
    }
	
	for(int i=0; i<=sizeof(*pollS);i++){
		printf("%s","%s",pollS[i].pollName,pollS[i].pollNum);
		fprintf(fptr, "%s","%s",pollS[i].pollNum);
	}
	fclose(fp);
	fclose(fptr);
}

void Changepassword(struct account accounts[], char* username)
{
    	FILE *fp;
	FILE *fptr;
    	int i=0;   // count how many lines are in the file
    	int c;
	char pass[50];

    	fp=fopen("users.txt", "r");
    	while(!feof(fp))
	{
        	c=fgetc(fp);
        	if(c=='\n')
            	++i;
    	}

    	int j=0;
    	rewind(fp);  // Line I addedread each line and put into accounts
    	while(i>0)
    	{
        	fscanf(fp, "%s,%s", accounts[j].username, accounts[j].password);
        	++j;
		--i;
    	}

	fclose(fp);
	printf("Enter new Password:");
	scanf("%s",pass);

	for(int i=0 ; i<= sizeof(*accounts); i++)
	{
		if(accounts[j].username == username)
		{
			accounts[j].password == pass;
		}
	}

	fp=fopen("users.txt", "a");
	fprintf(fptr, "%s", accounts);
	fclose(fptr);
}

void DisplayPollResults()
{
	char pollNumber[];
	char PollDescription[];
	int WardNo;
	 PollDate;
	
	printf("Enter Poll Number");
	scanf("%s",pollNumber);
	
	FILE *in_file = fopen( const char * “polls.txt" , const char * r );
	FILE *in_file1 = fopen( const char * “pollresults.txt", const char * r );
	
	While(in_file){
		if(pollNumber == in_file[Poll No]){
			PollDescription = in_file[i].Poll Description;
			WardNo = in_file[i].Ward No;
			PollDate = in_file[i].Poll Date;
			print("Poll No - "+pollNumber);
			print("\n");
			print("Poll Description - "+PollDescription);
			print("\n");
			print("Ward No - "+WardNo);
			print("\n");
			print("Poll Date - "+PollDate);
			print("\n");
		}
	}
	
	While(in_file1){
		print("Candidate Name ");
		print("Number of votes ");
		print("\n");
		if(pollNumber == in_file1[j].Poll No){
			print(in_file1[Candidate Name]);
			print(in_file1[Number of votes]);
			print("\n");
		}
	}
	 fclose(in_file);
	 fclose(in_file1);	
}
