#include <stdio.h>

#include <assert.h>

#include <stdlib.h>

#include <string.h>

#include <ctype.h>

#include <time.h>

#include <unistd.h>


struct Spaceship {
  char * name;
  int age;
  int warp_speed;
  int crew;

};

struct Spaceship * star_trek;
struct Spaceship * pegasos;
struct Spaceship * space_dog;
struct Spaceship * star_fighter;

struct Spaceship * Spaceship_create(char * name, int age, int warp_speed, int crew);

void Spaceship_destroy(struct Spaceship * who);

void Spaceship_print(struct Spaceship * who);

void Spaceship_updateAge(struct Spaceship * spaceship1, struct Spaceship * spaceship2, struct Spaceship * spaceship3, struct Spaceship * spaceship4);

void Spaceship_updateCrew(struct Spaceship * spaceship1, struct Spaceship * spaceship2, struct Spaceship * spaceship3, struct Spaceship * spaceship4);
void Spaceship_sortingWarp_Speed(struct Spaceship * spaceship1, struct Spaceship * spaceship2, struct Spaceship * spaceship3, struct Spaceship * spaceship4);
void Spaceship_randomNumber(struct Spaceship * who);
void update_Spaceship_Name(struct Spaceship * who);
void display_Spaceship(struct Spaceship * spaceship3, struct Spaceship * spaceship4);

int main() {

  srand(time(NULL)); /* Intializes random number generator */

  star_trek = Spaceship_create(
    "Star Trek", 32, 64, 140);

  pegasos = Spaceship_create(
    "Pegasos I", 20, 72, 180);

  space_dog = Spaceship_create(
    "Space Dog III", 28, 22, 200);

  star_fighter = Spaceship_create(
    "Star Fighter", 10, 90, 35);

  printf("Star Trek is at memory location %p:\n", star_trek);
  Spaceship_print(star_trek);

  printf("Pegasos I is at memory location %p:\n", pegasos);
  Spaceship_print(pegasos);

  printf("Space Dog III is at memory location %p:\n", space_dog);
  Spaceship_print(space_dog);

  printf("Star Fighter is at memory location %p:\n", star_fighter);
  Spaceship_print(star_fighter);

  printf("Update Star_Trek\n");
  star_trek -> age += 20;
  star_trek -> warp_speed -= 2;
  star_trek -> crew += 40;
  Spaceship_print(star_trek);

  printf("Update Pegasos\n");
  pegasos -> age += 20;
  pegasos -> crew += 20;
  Spaceship_print(pegasos);

  Spaceship_updateAge(star_trek, pegasos, space_dog, star_fighter);

  Spaceship_updateCrew(star_trek, pegasos, space_dog, star_fighter);

  
    Spaceship_randomNumber(star_trek);
    Spaceship_print(star_trek);
    Spaceship_randomNumber(pegasos);
     Spaceship_print(pegasos);
    Spaceship_randomNumber(space_dog);
    Spaceship_print(space_dog);
    Spaceship_randomNumber(star_fighter);
    Spaceship_print(star_fighter);
    
  Spaceship_sortingWarp_Speed(star_trek,pegasos,space_dog,star_fighter); 

   update_Spaceship_Name(space_dog);
   Spaceship_print(space_dog);

  Spaceship_destroy(star_trek);
  Spaceship_destroy(pegasos);

  display_Spaceship(space_dog, star_fighter);

  return 0;
}

void display_Spaceship(struct Spaceship * spaceship3, struct Spaceship * spaceship4) {
  int min, max, minPos, array[2], sortingArray[2], number;
  char * name[] = {
    " ",
    " "
  };

  struct Spaceship * ptr[2] = {

    spaceship3,
    spaceship4
  };
  for (int i = 0; i < 2; i++) {
    array[i] = ptr[i] -> age;

  }

  for (int i = 0; i < 4; i++) {

    max = (ptr[i]) -> age;

    for (int j = 0; j < 4; j++) {

      if (max < (ptr[j]) -> age) {

        min = max;
        max = (ptr[j]) -> age;

      } else if ((ptr[j]) -> age < min && min < max) {

        min = (ptr[j]) -> age;

      }

    }

  }

  printf("\n");
  printf("#########_Update/Sorting Age_After Destroed Spaceship ##########\n");
  for (int i = 0; i < 4; i++) {

    if (min == (ptr[i]) -> age) {

      printf("------------------------\n");
      printf("Name: %s\n", ptr[i] -> name);
      printf("\tAge: %d\n", ptr[i] -> age);
      printf("\tWarp Speed: %d\n", (ptr[i]) -> warp_speed);
      printf("\tCrew: %d\n", (ptr[i]) -> crew);
    }

  }

  printf("\n###############################\n");
  printf("\n");

}

void update_Spaceship_Name(struct Spaceship * who) {
  char userChoice[1];
  const char name[] = {
    "nothing"
  };
  char numbers[] = {
    '0',
    '1',
    '2',
    '3',
    '4',
    '5',
    '6',
    '7',
    '8',
    '9'
  };
  char * ret;
  int size = sizeof(name) / sizeof(name[0]);
  char legalChoiceYes[] = {
    "y"
  };
  char legalChoiceNo[] = {
    "n"
  };

  printf("Do you want to update %s  name? ( y for yes or n for no)\n", who -> name);
  scanf("%s", userChoice);

  while ((strcmp(userChoice, legalChoiceYes) != 0) && (strcmp(userChoice, legalChoiceNo) != 0)) {
    printf("Invalid Input.Enter y for Yes or n for No :\n");
    scanf("%s", userChoice);

  }
  int exclamationCheck = 0;
  if (strcmp(userChoice, legalChoiceYes) == 0) {

    do {
      if (exclamationCheck == 0) {

        printf("Enter  a name for %s spaceship: \n", who -> name);
        scanf("%s", name);

      } else if (exclamationCheck == 1) {
        printf("Invalid Input.Please enter  a name for %s spaceship: \n", who -> name);
        scanf("%s", name);
      }
      exclamationCheck = 0;

      for (int j = 0; j < 10; j++) {
        if (strchr(name, numbers[j]) != NULL) {
          exclamationCheck = 1;
          break;
        }

      }

    } while (exclamationCheck == 1);

    printf("The new name of %s spaceship is: ", who -> name);
    strcpy(who -> name, name);
    printf("%s \n", who -> name);

  }

}

void Spaceship_sortingWarp_Speed(struct Spaceship * spaceship1, struct Spaceship * spaceship2, struct Spaceship * spaceship3, struct Spaceship * spaceship4) {
  struct Spaceship * ptr[4] = {
    spaceship1,
    spaceship2,
    spaceship3,
    spaceship4
  };
  const char * name[] = {
    " ",
    " ",
    " ",
    " "
  };
  int max, min, maxPos, array[4], sortingArray[4];

  for (int i = 0; i < 4; i++) {

    array[i] = ptr[i] -> warp_speed;
  }

  for (int i = 0; i < 4; i++) {
    max = array[i];
    min = 0;
    for (int j = 0; j < 5; j++) {
      if (max < array[j]) {

        max = array[j];
        maxPos = j;

      } else if (max > array[j] && max == array[i]) {
        maxPos = i;

      } else if (max == array[j]) {
        max = array[j];
        maxPos = j;
      }

    }

    sortingArray[i] = max;

    array[maxPos] = min;

  }

  printf("\n");
  printf("#########_Sorting_Warp_Speed_##########\n");
  for (int i = 0; i < 4; i++) {

    for (int j = 0; j < 4; j++) {

      if (sortingArray[i] == (ptr[j]) -> warp_speed && strcmp(name[j], ptr[j] -> name) != 0) {
        name[j] = (ptr[j]) -> name;

        printf("------------------------\n");
        printf("Name: %s\n", (ptr[j]) -> name);
        printf("\tAge: %d\n", (ptr[j]) -> age);
        printf("\tWarp Speed: %d\n", (ptr[j]) -> warp_speed);
        printf("\tCrew: %d\n", (ptr[j]) -> crew);

      }
    }

  }
  printf("###############################\n");
  printf("\n");

}

void Spaceship_randomNumber(struct Spaceship * who) {
  int lower = 1, upper = 11, randomNumber;

  printf("########_Print_Random_Warp_Speed_#########\n");

  randomNumber = (rand() % (upper - lower + 1) + lower);

  who -> warp_speed = randomNumber;

}

void Spaceship_updateCrew(struct Spaceship * spaceship1, struct Spaceship * spaceship2, struct Spaceship * spaceship3, struct Spaceship * spaceship4) {

  struct Spaceship * ptr[4] = {
    spaceship1,
    spaceship2,
    spaceship3,
    spaceship4
  };
  int min, max, maxPos, updateCrew, array[4], sortingArray[4];

  for (int i = 0; i < 4; i++) {

    max = (ptr[i]) -> crew;

    for (int j = 0; j < 4; j++) {

      if (max < (ptr[j]) -> crew) {

        min = max;
        max = (ptr[j]) -> crew;

      } else if ((ptr[j]) -> crew < min && min < max) {

        min = (ptr[j]) -> crew;
      }

    }

  }

  printf("-----Crew-----\n");
  printf("Max: %d\n", max);
  printf("Min: %d\n", min);
  printf("-----Crew-----\n");

  for (int i = 0; i < 4; i++) {

    if ((ptr[i]) -> crew == max) {
      updateCrew = max / 2;

    }

    if (updateCrew != 0 && (ptr[i]) -> crew == min) {
      (ptr[i]) -> crew = (ptr[i]) -> crew + updateCrew;
      min = (ptr[i]) -> crew;
      printf("\n");
      printf("#########_Update Crew_##########\n");
      printf("------------------------\n");
      printf("Name: %s\n", ptr[i] -> name);
      printf("\tAge: %d\n", ptr[i] -> age);
      printf("\tWarp Speed: %d\n", (ptr[i]) -> warp_speed);
      printf("\tCrew: %d\n", (ptr[i]) -> crew);
      printf("###############################\n");
      printf("\n");
    }

    array[i] = ptr[i] -> crew;
  }

  for (int i = 0; i < 4; i++) {

    max = array[i];

    for (int j = 0; j < 4; j++) {

      if (max < array[j]) {

        max = array[j];
        maxPos = j;

      } else if (max > array[j] && max == array[i]) {
        maxPos = i;

      } else if (max == array[j]) {
        max = array[j];
        maxPos = j;
      }
    }

    sortingArray[i] = max;

    array[maxPos] = min;

  }
  int count = 0;
  char * name[] = {
    " ",
    " ",
    " ",
    " "
  };
  printf("\n");
  printf("#########_Sorting Crew_##########\n");
  for (int i = 0; i < 4; i++) {

    for (int j = 0; j < 4; j++) {

      if (sortingArray[i] == (ptr[j]) -> crew && strcmp(name[j], ptr[j] -> name) != 0) {

        name[j] = (ptr[j]) -> name;

        printf("------------------------\n");
        printf("Name: %s\n", (ptr[j]) -> name);
        printf("\tAge: %d\n", (ptr[j]) -> age);
        printf("\tWarp Speed: %d\n", (ptr[j]) -> warp_speed);
        printf("\tCrew: %d\n", (ptr[j]) -> crew);
        //break;

      }

    }
  }

  printf("###############################\n");
  printf("\n");

}

void Spaceship_updateAge(struct Spaceship * spaceship1, struct Spaceship * spaceship2, struct Spaceship * spaceship3, struct Spaceship * spaceship4) {

  char userChoice[1];
  char legalChoiceYes[] = {
    "y"
  };
  char legalChoiceNo[] = {
    "n"
  }, age[1];
  int min, max, minPos, array[4], sortingArray[4], number;
  char * name[] = {
    " ",
    " ",
    " ",
    " "
  };

  struct Spaceship * ptr[4] = {
    spaceship1,
    spaceship2,
    spaceship3,
    spaceship4
  };

  printf("Do you want to update age of Spaceships? (Y or y for yes or n or N for no)\n");
  scanf("%s", userChoice);

  while ((strcmp(userChoice, legalChoiceYes) != 0) && (strcmp(userChoice, legalChoiceNo) != 0)) {
    printf("Invalid Input.Enter y for Yes or n for No :\n");
    scanf("%s", userChoice);

  }
  if (strcmp(userChoice, legalChoiceYes) == 0) {

    for (int i = 0; i < 4; i++) {

      printf("Enter age[1-90] for Spaceship %s :\n", (ptr[i]) -> name);
      scanf("%s", age);
      number = atoi(age);
      if (number > 0 && number <= 90) {
        (ptr[i]) -> age = number;
        array[i] = number;

      } else {

        do {
          printf("Invalid Input. Please enter a valid number:\n");
          scanf("%s", age);
          number = atoi(age);

        } while (number < 0 || number > 90);
        (ptr[i]) -> age = number;
        array[i] = number;

      }

    }
  } else {
    for (int i = 0; i < 4; i++) {

      array[i] = (ptr[i]) -> age;

    }
  }

  for (int i = 0; i < 4; i++) {

    min = array[i];
    max = array[i];

    for (int j = 0; j < 4; j++) {

      if (max < array[j]) {
        max = array[j] + 1;
      }

      if (min > array[j]) {

        min = array[j];
        minPos = j;

      } else if (min < array[j] && min == array[i]) {
        minPos = i;

      } else if (min == array[j]) {

        min = array[j];
        minPos = j;
      }
    }

    sortingArray[i] = min;

    array[minPos] = max;

  }

  printf("\n");
  printf("#########_Update/Sorting Age_##########\n");
  for (int i = 0; i < 4; i++) {

    for (int j = 0; j < 4; j++) {

      if (sortingArray[i] == (ptr[j]) -> age && strcmp(name[j], ptr[j] -> name) != 0) { // na to doume

        name[j] = (ptr[j]) -> name;

        printf("------------------------\n");
        printf("Name: %s\n", ptr[j] -> name);
        printf("\tAge: %d\n", ptr[j] -> age);
        printf("\tWarp Speed: %d\n", (ptr[j]) -> warp_speed);
        printf("\tCrew: %d\n", (ptr[j]) -> crew);

      }

    }
  }
  printf("###############################\n");
  printf("\n");

}

struct Spaceship * Spaceship_create(char * name, int age, int warp_speed, int crew) {
  struct Spaceship * who = (struct Spaceship * ) malloc(sizeof(struct Spaceship));
  assert(who != NULL);

  who -> name = strdup(name);
  who -> age = age;
  who -> warp_speed = warp_speed;
  who -> crew = crew;

  return who;
}

void Spaceship_destroy(struct Spaceship * who) {
  assert(who != NULL);

  free(who -> name);

  free(who);

}

void Spaceship_print(struct Spaceship * who) {
  printf("Name: %s\n", who -> name);
  printf("\tAge: %d\n", who -> age);
  printf("\tWarp Speed: %d\n", who -> warp_speed);
  printf("\tCrew: %d\n", who -> crew);
}
