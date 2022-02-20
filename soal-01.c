/*EL2208 Praktikum Pemecahan Masalah dengan C 2021/2022
*Modul            : 2 - Strings and External Files
*Percobaan        : -
*Hari dan Tanggal : Rabu, 23 Februari 2022
*Nama (NIM)       : -
*Asisten (NIM)    : -
*Nama File        : soal-01.c
*Deskripsi        : -
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Panjang maksimum kata
#define MAX_LEN 255


int main() 
{
	//deklarasi variabel-variabel yang akan digunakan
	char filename[MAX_LEN];
	char line[MAX_LEN];
	char baris1[MAX_LEN];
	char baris2[MAX_LEN];
	char baris3[MAX_LEN];
	char baris4[MAX_LEN];
	char baris5[MAX_LEN];
	char temp[MAX_LEN];
	char sandi[MAX_LEN];
	int index1=0, index2=0, index3=0;
	int panjang1, panjang2, panjang3;
	int jumlah1, jumlah2, jumlah3;
			
	//input nama file dan membuka file
	printf("Masukkan nama file: ");
	scanf("%s", &filename);
	FILE* stream = fopen(filename, "r");
	
	//memasukkan kelima baris dari dalam file ke variabel baru
	char* token;
	
	fgets(line, MAX_LEN, stream);
	token = strtok(line, "\n");
	strcpy(baris1, token);
	
	fgets(line, MAX_LEN, stream);
	token = strtok(line, "\n");
	strcpy(baris2, token);
	
	fgets(line, MAX_LEN, stream);
	token = strtok(line, "\n");
	strcpy(baris3, token);
	
	fgets(line, MAX_LEN, stream);
	token = strtok(line, "\n");
	strcpy(baris4, token);
	
	fgets(line, MAX_LEN, stream);
	token = strtok(line, "\n");
	strcpy(baris5, token);
	
	fclose(stream);
	
	//mencari indeks dan panjang kata dari setiap baris
	
	int found=0;
	while(found == 0 && index1!=strlen(baris1)-1){
		if(strncmp(baris1+index1,baris2,strlen(baris2))==0){
			found = 1;
			index1+=1;
		}
		else{
			index1+=1;
		}
	}
	panjang1 = strlen(baris2);
	
	found = 0;
	while(found == 0 && index2!=strlen(baris1)-1){
		if(strncmp(baris1+index2,baris3,strlen(baris3))==0){
			found = 1;
			index2+=1;
		}
		else{
			index2+=1;
		}
	}
	panjang2 = strlen(baris3);
	
	found = 0;
	while(found == 0 && index3!=strlen(baris1)-1){
		if(strncmp(baris1+index3,baris4,strlen(baris4))==0){
			found = 1;
			index3+=1;
		}
		else{
			index3+=1;
		}
	}
	panjang3 = strlen(baris4);
	
	//mengalikan setiap index dengan panjang, kemudian menyusunnya
	jumlah1 = index1*panjang1;
	sprintf(temp,"%d",jumlah1);
	strcpy(sandi, temp);

	
	jumlah2 = index2*panjang2;
	sprintf(temp,"%d",jumlah2);
	strcat(sandi, temp);

	
	jumlah3 = index3*panjang3;
	sprintf(temp,"%d",jumlah3);
	strcat(sandi, temp);

	
	//cetak output berdasarkan kata di baris kelima
	printf("Kata sandi untuk membuka truk: ");
	
	if (strncmp(baris5,"ikuzo",5)==0){
		for(int i = strlen(sandi)-1;i>=0;i--){
			printf("%c", sandi[i]);
		}
	}
	
	else{
		printf("%s\n", sandi);
	}

	return 0;
	
}
