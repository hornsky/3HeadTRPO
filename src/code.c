#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct vot {
  char surname[10];
  int grade_book;
  int grade[3];
} pp1;

void input();
void print();
void add();
void find2();

int main() {
  char c;

  while (1) {
    system("CLS");

    puts("1 - New jutnal.");
    puts("2 - Check jurnal.");
    puts("3 - Add in jurnal.");
    puts("4 - Find 2 and change.");
    puts("0 - exit.");

    c = getch();

    switch (c) {
    case '1':
      input();
      break;
    case '2':
      print();
      break;
    case '3':
      add();
      break;
    case '4':
      find2();
      break;
    case '0':
      return (0);
    default:
      puts("WRONG MODE");
      getch();
    }
  }
}

void input(FILE *dv) {
  int i;
  char ch;
  dv = fopen("jurnal.dat", "wb");

  system("CLS");

  printf("Enter student.\n");

  do {
    printf("\nStudent surname : ");
    scanf("%s", pp1.surname);

    printf("Gradebook number : ");
    scanf("%d", &pp1.grade_book);

    for (i = 0; i <= 3; i++) {
      printf("Enter %d number grade : ", i + 1);
      scanf("%d", &pp1.grade[i]);

      if ((pp1.grade[i] < 2) || (pp1.grade[i] > 5)) {
        puts("\nERROR : area of your grade[2-5]. try again.\n");
        i--;
      }
    }

    fwrite(&pp1, sizeof(pp1), 1, dv);

    printf("end? y/n\n");

    ch = getch();
  } while (ch == 'n');

  fclose(dv);
}

void print(FILE *dv) {
  system("CLS");

  int i, j;

  dv = fopen("jurnal.dat", "rb");

  fread(&pp1, sizeof(pp1), 1, dv);

  i = 1;

  while (!feof(dv)) {
    printf("Student %d.\nSurname : %s\nGrade book : %d", i, pp1.surname,
           pp1.grade_book);
    for (j = 0; j <= 3; j++)
      printf("\n%d Number grade is %d.", j + 1, pp1.grade[j]);
    printf("\n\n");
    i++;
    fread(&pp1, sizeof(pp1), 1, dv);
  }

  fclose(dv);
  getch();
}

void add(FILE *dv) {
  system("CLS");
  int i;
  char ch;

  dv = fopen("jurnal.dat", "ab");

  printf("Enter student.\n");

  do {
    printf("\nStudent surname : ");
    scanf("%s", pp1.surname);

    printf("Gradebook number : ");
    scanf("%d", &pp1.grade_book);

    for (i = 0; i <= 3; i++) {
      printf("Enter %d number grade : ", i + 1);
      scanf("%d", &pp1.grade[i]);
      

       if ((pp1.grade[i] < 2) || (pp1.grade[i] > 5)) {
         puts("\nERROR : area of your grade[2-5]. try again.\n");
         i--;
      }
    }

    fwrite(&pp1, sizeof(pp1), 1, dv);

    printf("end? y/n");
    ch = getch();
  } while (ch == 'n');
  fclose(dv);
}

void find2(FILE *dv) {
  system("CLS");
  int i;
  long int j;
  char ch;
  dv = fopen("jurnal.dat", "rb+");

  fread(&pp1, sizeof(pp1), 1, dv);

  while (!feof(dv)) {
    for (i = 0; i <= 3; i++) {
      if (pp1.grade[i] == 2) {
        printf("Surname : %s\nGrade book : %d\n%d Number grade is %d\n",
               pp1.surname, pp1.grade_book, i + 1, pp1.grade[i]);
        printf("\nDo you want change %d number grade? : y/n\n", i + 1);
        ch = getch();

        if (ch == 'y') {
          printf("\nWhat grade do you want to change? : ");
          scanf("%d", &pp1.grade[i]);

          j = sizeof(pp1);

          fseek(dv, -j, SEEK_CUR);
          fwrite(&pp1, sizeof(pp1), 1, dv);
          fflush(dv);
          printf("\nchanges are successful\n");
          printf("%d Number grade is %d\n", i + 1, pp1.grade[i]);
          getch();
          printf("\n");
        }
      }
    }
    fread(&pp1, sizeof(pp1), 1, dv);
  }
  fclose(dv);
}
