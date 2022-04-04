#include "header.h"


void show()	;
void inf()	;
void med()  ;
void total();
void delet();
void table();
void remo();
void newd();

void select_doc()
		    {
		        system("CLS");
				char o[30],f[30],r[5];
				unsigned int s,d,h,m,a,z,mom,stop=0,i;
				
				for(i=0;i!=-1;i++)
				{
					system("CLS");
				    printf("\n\n     To Enter New Doctor T_Table <----------Press 2-------->\n");
				    printf("     For One Doctor Time Table   <--------- Press 3-------->\n");
				    printf("     Remove Doctor Time Table   <---------- Press 4-------->\n");
				    printf("     >> ");
				    scanf(" %d",&s);
				    if(s > 1 && s <= 4)
					{
                    switch(s)
                    {
                    	case 2:
                    		newd();
                    		break;
                    	case 3:
						    table();
							break;
						case 4:
						    remo();
							break;
						}
				   	}
				   	else{
				   			printf("\n     Press Only <2---3---4--->\n");
							printf("\n     Enter Any Digit OR Ctrl+Z for End \n");
		                	printf("\n     %s", "? " );
                            scanf( "%d", &mom);   
						    break;
					   }
				   }
			}
				void newd()	
					{
						char o[30],f[30],r[5];
			        	unsigned int s,d,h,m,a,z,mom,stop=0,i;
                        FILE *cfp;	
	                    if((cfp=fopen("Doctor.txt", "a" ))==NULL)
                        {
	                        puts("File could not be opened");
                        }
                        else
                        {
                            while (!feof( stdin) )
						    {
				                printf("     Doctor Name: ");
					            fflush(stdin);
                                gets(o) ;
					            printf("     Doctor ID  : ");
					            scanf("%d",&d);
				            	printf("     Doctor Age: ");
				            	scanf("%d",&a);
				                printf("     Gender : ");
				            	fflush(stdin);
                                gets(f) ;
				            	printf("     Doctor Time Hour: ");
				            	scanf("%d",&h);
				            	printf("     Doctor Time Min : ");
				            	scanf("%d",&m);	
					            printf("     AM OR PM : ");
					            fflush(stdin);
                                gets(r) ;				
					            fprintf(cfp,"%29s %d %d %29s %d %d %4s\n",o,d,a,f,h,m,r);
					            printf("\n     Enter ctrl+z for end OR 1,2,3... to new Doctor\n\n");
			                    printf( "     %s", "? " );
                                scanf( "%d", &mom);					
					        }
				    	    fclose(cfp);
				        }
		         	}
				void table()
					{
					    char o[30],f[30],r[5];
			         	unsigned int s,d,h,m,a,z,mom,stop=0,i;								
				    	FILE *read;
                        if((read=fopen("Doctor.txt", "r" ))==NULL)
                        {
	                        puts("File could not be opened");
                        }
                        else
					    {
				            printf("     Write Doctor ID = ");
					        scanf("%d",&z);	
	                        while(!feof(read))
                	        {
                	            fscanf(read,"%29s %d %d %29s %d %d %4s",o,&d,&a,f,&h,&m,r);
                	            if(d==z)
	                            {
	                        	    stop=1;
		                            printf("\n        D_Name  =  %s\n",o);
		                            printf("     Doctor ID  =  %d\n",d);
		                            printf("           Age  =  %d\n",a);
								    printf("        Gender  =  %s\n",f); 
		                            printf("       D_Timing =  %d:%d %s\n",h,m,r);
    	                            break;		                    
    	                        }
							}
    	                    if (stop==0)
							{
    	                        printf("\n     This ID: %d Don't Match With Doctor ID!\n", z);
			            	}
			            	printf("\n     Enter ctrl+z for End \n");
							printf( "\n     %s", "? " );
                            scanf( "%d", &mom);
							fclose( read );
					    }
				    }
				void remo()	
				    {
				    	char o[30],f[30],r[5];
			        	unsigned int s,d,h,m,a,z,mom,stop=0,i;
			        	int ruk=0;
				    	system ("CLS");
                        FILE *cfr,*cr;
                        if((cfr=fopen("Doctor.txt", "r" ))==NULL)
                        {
		                    puts("File could not be opened");
	                    }
                        else
                        {
                          	printf("     Doctor ID: ");
            	            scanf("%d",&z);
	                        while(!feof(cfr))
        	                {
	        	                fscanf(cfr,"%29s %d %d %29s %d %d %4s",o,&d,&a,f,&h,&m,r);
		                        if(d==z)
			                   	{
			                   	    ruk=1;
				                    if(!feof(cfr))
			                    	{
		                                printf("\n        D_Name  =  %s\n",o);
		                                printf("     Doctor ID  =  %d\n",d);
		                                printf("           Age  =  %d\n",a);
								        printf("        Gender  =  %s\n",f); 
		                                printf("       D_Timing =  %d:%d %s\n",h,m,r);
		                                printf("\n     Record Of Doctor <%s> Has Been Delete\n",o);
	                                }
								}
                                else
		                     	{
		                            if((cr=fopen("hosp.txt","a"))==NULL)
				                    {
	                                    puts("File could not be opened");
		                            }
            	                    else
				                    {
		                                if(!feof(cfr))
				                 	    {
    		                                fprintf(cr,"%29s %d %d %29s %d %d %4s\n",o,d,a,f,h,m,r);
		                                }
	                                }
	                                fclose(cr);
                                }
                            }  
                                fclose(cfr);
                        }
                        remove("Doctor.txt");
                        rename("hosp.txt","Doctor.txt");
				    	if(ruk==0)
			        	{
    		    	    	printf("\n     Doctor of ID: %d Not Exist\n",z);
					    }
					    printf("\n     Enter Any Digit OR Ctrl+Z for End \n");
						printf( "\n     %s", "? " );
                        scanf( "%d", &mom);
			    	}


