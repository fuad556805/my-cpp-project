#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>

// ================== Data Structures ==================

// Linked List for Patient Records
typedef struct Patient {
    char name[50];
    char gender[10];
    int age;
    float weight;
    float height;
    float heartRate;
    float bloodPressure;
    float temperature;
    struct Patient* next;
} Patient;

// Queue for Medicine Reminders
typedef struct ReminderNode {
    char medicine[50];
    char time[10];
    int seconds;
    struct ReminderNode* next;
} ReminderNode;

typedef struct {
    ReminderNode *front, *rear;
} ReminderQueue;

// Binary Search Tree for Doctors/Hospitals
typedef struct Hospital {
    char name[100];
    char address[200];
    char contact[20];
    char area[50];
    struct Hospital *left, *right;
} Hospital;

// Hash Table for Symptoms/Diseases
#define TABLE_SIZE 11
typedef struct Disease {
    char name[50];
    char remedy[500];
    char medicine[100];
    char doctor[50];
    int symptoms[11];
    struct Disease* next;
} Disease;

typedef struct {
    Disease* table[TABLE_SIZE];
} DiseaseHashTable;

// ================== Global Variables ==================
Patient* currentPatient = NULL;
ReminderQueue reminderQueue = {NULL, NULL};
Hospital* hospitalTree = NULL;
DiseaseHashTable diseaseDB;

// ================== Function Prototypes ==================
// Utility Functions
int timeToSeconds(char *time);
void clearInputBuffer();

// Patient Functions
void patientDetails();
void addPatientToFile(Patient* patient);
void displayPatient(Patient* patient);

// Health Check Functions
float calculateBMI(float weight, float height);
void healthCheck();

// Disease/Symptom Functions
void initializeDiseaseDB();
unsigned int hashFunction(int symptoms[]);
void addDiseaseToHashTable(Disease* disease);
void checkSymptoms();

// Reminder Functions
void initReminderQueue();
void enqueueReminder(char medicine[], char time[]);
void setReminder();
void processReminders();

// Hospital/Doctor Functions
void initHospitalTree();
Hospital* insertHospital(Hospital* root, Hospital* newHospital);
void showDoctorDetails();
void searchHospitalsInArea(Hospital* root, const char* area);

// Main Menu
void displayMainMenu();

// ================== Main Function ==================
int main() {
    // Initialize data structures
    initHospitalTree();
    initializeDiseaseDB();
    initReminderQueue();

    int choice;
    while (1) {
        displayMainMenu();
        printf("\nChoose an option: ");
        scanf("%d", &choice);
        clearInputBuffer();

        switch (choice) {
            case 1:
                patientDetails();
                break;
            case 2:
                if (currentPatient == NULL) {
                    printf("\nPlease enter patient details first (Option 1).\n");
                } else {
                    healthCheck();
                }
                break;
            case 3:
                checkSymptoms();
                break;
            case 4:
                setReminder();
                break;
            case 5:
                showDoctorDetails();
                break;
            case 6:
                printf("\nExiting...\n");

                // Clean up memory
                while (currentPatient != NULL) {
                    Patient* temp = currentPatient;
                    currentPatient = currentPatient->next;
                    free(temp);
                }

                while (reminderQueue.front != NULL) {
                    ReminderNode* temp = reminderQueue.front;
                    reminderQueue.front = reminderQueue.front->next;
                    free(temp);
                }

                // TODO: Add cleanup for hospitalTree and diseaseDB

                exit(0);
            default:
                printf("\nInvalid input! Choose 1-6.\n");
        }
    }

    return 0;
}

// ================== Utility Functions ==================
int timeToSeconds(char *time) {
    int hours, minutes, seconds;
    sscanf(time, "%d:%d:%d", &hours, &minutes, &seconds);
    return hours * 3600 + minutes * 60 + seconds;
}

void clearInputBuffer() {
    while (getchar() != '\n');
}

// ================== Patient Functions ==================
void patientDetails() {
    Patient* newPatient = (Patient*)malloc(sizeof(Patient));

    printf("\n==== Enter Patient Details ====\n");
    printf("Name: ");
    fgets(newPatient->name, 50, stdin);
    newPatient->name[strcspn(newPatient->name, "\n")] = '\0';

    printf("Gender (Male/Female/Other): ");
    fgets(newPatient->gender, 10, stdin);
    newPatient->gender[strcspn(newPatient->gender, "\n")] = '\0';

    printf("Age: ");
    scanf("%d", &newPatient->age);

    printf("Weight (kg): ");
    scanf("%f", &newPatient->weight);

    printf("Height (m): ");
    scanf("%f", &newPatient->height);

    printf("Heart Rate (bpm): ");
    scanf("%f", &newPatient->heartRate);

    printf("Blood Pressure (mmHg): ");
    scanf("%f", &newPatient->bloodPressure);

    printf("Body Temperature (Fahrenheit): ");
    scanf("%f", &newPatient->temperature);
    clearInputBuffer();

    // Add to linked list
    newPatient->next = currentPatient;
    currentPatient = newPatient;

    // Add to file (for persistence)
    addPatientToFile(newPatient);

    displayPatient(newPatient);
}

void addPatientToFile(Patient* patient) {
    FILE* file = fopen("patients.txt", "a");
    if (file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    fprintf(file, "%s|%s|%d|%.2f|%.2f|%.2f|%.2f|%.2f\n",
            patient->name, patient->gender, patient->age,
            patient->weight, patient->height, patient->heartRate,
            patient->bloodPressure, patient->temperature);

    fclose(file);
}

void displayPatient(Patient* patient) {
    printf("\nPatient Name: %s\nGender: %s\nAge: %d years\n",
           patient->name, patient->gender, patient->age);
    printf("Weight: %.2f kg\nHeight: %.2f m\n", patient->weight, patient->height);
    printf("Heart Rate: %.2f bpm\nBlood Pressure: %.2f mmHg\n",
           patient->heartRate, patient->bloodPressure);
    printf("Body Temperature: %.2f°F\n", patient->temperature);
}

// ================== Health Check Functions ==================
float calculateBMI(float weight, float height) {
    return weight / (height * height);
}

void healthCheck() {
    float bmi = calculateBMI(currentPatient->weight, currentPatient->height);
    float normalBP_low = 90.0, normalBP_high = 120.0;
    float normalHR_low = 60.0, normalHR_high = 100.0;
    float normalTemp_low = 97.0, normalTemp_high = 99.0;

    printf("\n==== Health Check ====\n");
    printf("Your BMI: %.2f\n", bmi);

    if (bmi < 18.5) {
        printf("Advice: You are underweight. Eat nutritious food.\n");
    } else if (bmi < 24.9) {
        printf("Advice: Your weight is normal. Maintain a healthy lifestyle.\n");
    } else if (bmi < 29.9) {
        printf("Advice: You are overweight. Exercise regularly.\n");
    } else {
        printf("Advice: You are obese. Consult a doctor.\n");
    }

    printf("\nNormal Blood Pressure: %.2f - %.2f mmHg\n", normalBP_low, normalBP_high);
    if (currentPatient->bloodPressure >= normalBP_low && currentPatient->bloodPressure <= normalBP_high) {
        printf("Your BP is normal.\n");
    } else {
        printf("Your BP is NOT normal: Sit or lie down, stay calm, drink water, avoid salt, and seek medical help.\n");
    }

    printf("\nNormal Heart Rate: %.2f - %.2f bpm\n", normalHR_low, normalHR_high);
    if (currentPatient->heartRate >= normalHR_low && currentPatient->heartRate <= normalHR_high) {
        printf("Your Heart Rate is normal.\n");
    } else {
        printf("Your Heart Rate is NOT normal: Stay calm, breathe deeply, drink cold water, and see a doctor if it happens often.\n");
    }

    printf("\nNormal Body Temperature: %.2f - %.2f°F\n", normalTemp_low, normalTemp_high);
    if (currentPatient->temperature >= normalTemp_low && currentPatient->temperature <= normalTemp_high) {
        printf("Your Body Temperature is normal.\n");
    } else {
        printf("Your Body Temperature is NOT normal.\n");
        if (currentPatient->temperature > normalTemp_high) {
            printf("Remedy: You may have a fever. Rest, drink plenty of fluids, and take paracetamol if necessary.\n");
        } else {
            printf("Remedy: You may have hypothermia. Keep warm, drink warm fluids, and seek medical attention if symptoms persist.\n");
        }
    }
}

// ================== Disease/Symptom Functions ==================
void initializeDiseaseDB() {
    // Initialize hash table
    for (int i = 0; i < TABLE_SIZE; i++) {
        diseaseDB.table[i] = NULL;
    }

    // Common Cold
    Disease* cold = (Disease*)malloc(sizeof(Disease));
    strcpy(cold->name, "Common Cold");
    strcpy(cold->remedy, "Drink warm water, take steam, rest, consume honey and ginger tea, gargle with salt water, eat vitamin C-rich foods");
    strcpy(cold->medicine, "Cetirizine");
    strcpy(cold->doctor, "General Physician");
    memset(cold->symptoms, 0, sizeof(cold->symptoms));
    cold->symptoms[0] = 1; // Cold
    cold->symptoms[1] = 1; // Cough
    cold->symptoms[5] = 1; // Sore Throat
    addDiseaseToHashTable(cold);

    // Flu
    Disease* flu = (Disease*)malloc(sizeof(Disease));
    strcpy(flu->name, "Flu");
    strcpy(flu->remedy, "Rest, stay hydrated, drink herbal teas, use a humidifier, eat nutrient-rich foods, avoid cold drinks");
    strcpy(flu->medicine, "Paracetamol");
    strcpy(flu->doctor, "General Physician");
    memset(flu->symptoms, 0, sizeof(flu->symptoms));
    flu->symptoms[2] = 1; // Fever
    flu->symptoms[3] = 1; // Headache
    flu->symptoms[4] = 1; // Body Pain
    addDiseaseToHashTable(flu);

    // Add more diseases similarly...
}

unsigned int hashFunction(int symptoms[]) {
    // Simple hash function that sums the indices of present symptoms
    unsigned int hash = 0;
    for (int i = 0; i < 11; i++) {
        if (symptoms[i]) {
            hash += (i + 1);
        }
    }
    return hash % TABLE_SIZE;
}

void addDiseaseToHashTable(Disease* disease) {
    unsigned int index = hashFunction(disease->symptoms);

    disease->next = diseaseDB.table[index];
    diseaseDB.table[index] = disease;
}

void checkSymptoms() {
    char symptoms[11][50] = {
        "Cold", "Cough", "Fever", "Headache", "Body Pain",
        "Sore Throat", "Nausea", "Stomach Pain", "Diarrhea", "Skin Rash", "Shortness of Breath"
    };
    int userSymptoms[11] = {0};
    int count = 0;

    printf("\n==== Check Your Symptoms ====\n");
    for (int i = 0; i < 11; i++) {
        printf("%d. %s\n", i + 1, symptoms[i]);
    }
    printf("Enter the numbers of your symptoms (example: 1 3 5 and end with -1): ");

    int input;
    while (1) {
        scanf("%d", &input);
        if (input == -1) break;
        if (input >= 1 && input <= 11) {
            userSymptoms[input - 1] = 1;
            count++;
        }
    }
    clearInputBuffer();

    if (count == 0) {
        printf("\nNo symptoms entered. Please try again.\n");
        return;
    }

    printf("\n==== Possible Diseases ====\n");

    // Search in hash table
    unsigned int index = hashFunction(userSymptoms);
    Disease* current = diseaseDB.table[index];
    int matchFound = 0;

    while (current != NULL) {
        int match = 1;
        for (int i = 0; i < 11; i++) {
            if (current->symptoms[i] != userSymptoms[i]) {
                match = 0;
                break;
            }
        }

        if (match) {
            printf("\nDisease: %s\n", current->name);
            printf("Remedy: %s\n", current->remedy);
            printf("Medicine: %s\n", current->medicine);
            printf("Doctor: %s\n\n", current->doctor);
            matchFound = 1;
        }
        current = current->next;
    }

    if (!matchFound) {
        printf("\nNo exact match found. Showing possible conditions based on your symptoms:\n");
        for (int i = 0; i < 11; i++) {
            if (userSymptoms[i]) {
                printf("\nSymptom: %s\n", symptoms[i]);
                // Simple symptom-based advice
                if (i == 0) printf("Possible Condition: Common Cold\n");
                else if (i == 1) printf("Possible Condition: Bronchitis\n");
                else if (i == 2) printf("Possible Condition: Viral Fever\n");
                // Add more symptom-based conditions...
                break;
            }
        }
    }
}

// ================== Reminder Functions ==================
void initReminderQueue() {
    reminderQueue.front = reminderQueue.rear = NULL;
}

void enqueueReminder(char medicine[], char time[]) {
    ReminderNode* newNode = (ReminderNode*)malloc(sizeof(ReminderNode));
    strcpy(newNode->medicine, medicine);
    strcpy(newNode->time, time);
    newNode->seconds = timeToSeconds(time);
    newNode->next = NULL;

    if (reminderQueue.rear == NULL) {
        reminderQueue.front = reminderQueue.rear = newNode;
    } else {
        reminderQueue.rear->next = newNode;
        reminderQueue.rear = newNode;
    }
}

void setReminder() {
    char medicine[50], time[10];

    printf("\n==== Set Medicine Reminder ====\n");
    printf("Medicine Name: ");
    fgets(medicine, 50, stdin);
    medicine[strcspn(medicine, "\n")] = '\0';

    printf("Time (HH:MM:SS): ");
    fgets(time, 10, stdin);
    time[strcspn(time, "\n")] = '\0';

    enqueueReminder(medicine, time);
    printf("\nReminder set: Take %s at %s.\n", medicine, time);

    // Start countdown in a simple way (in real app, this would be a separate thread)
    printf("\nCountdown to reminder...\n");
    int totalSeconds = timeToSeconds(time);
    for (int i = totalSeconds; i > 0; i--) {
        printf("%d seconds remaining...\r", i);
        fflush(stdout);
        sleep(1);
    }
    printf("\nNOTIFICATION: Don't forget to take %s now!\n", medicine);
}

// ================== Hospital/Doctor Functions ==================
void initHospitalTree() {
    // Add hospitals to BST
    // Aftabnagar
    Hospital* nagorik = (Hospital*)malloc(sizeof(Hospital));
    strcpy(nagorik->name, "Nagorik Hospital");
    strcpy(nagorik->address, "House #59, Block-C, Main Road, Aftabnagar, Dhaka-1212");
    strcpy(nagorik->contact, "+8809600 990000");
    strcpy(nagorik->area, "Aftabnagar");
    nagorik->left = nagorik->right = NULL;
    hospitalTree = insertHospital(hospitalTree, nagorik);

    // Rampura - Farazy Hospital
    Hospital* farazy = (Hospital*)malloc(sizeof(Hospital));
    strcpy(farazy->name, "Farazy Hospital Ltd.");
    strcpy(farazy->address, "House #15-19, Block-E, Main Road, Banasree, Rampura, Dhaka-1219");
    strcpy(farazy->contact, "+8801766111317");
    strcpy(farazy->area, "Rampura");
    farazy->left = farazy->right = NULL;
    hospitalTree = insertHospital(hospitalTree, farazy);

    // Add more hospitals similarly...
}

Hospital* insertHospital(Hospital* root, Hospital* newHospital) {
    if (root == NULL) return newHospital;

    // Compare by area, then by name
    int cmp = strcmp(newHospital->area, root->area);
    if (cmp < 0) {
        root->left = insertHospital(root->left, newHospital);
    } else if (cmp > 0) {
        root->right = insertHospital(root->right, newHospital);
    } else {
        // Same area, compare by name
        cmp = strcmp(newHospital->name, root->name);
        if (cmp < 0) {
            root->left = insertHospital(root->left, newHospital);
        } else {
            root->right = insertHospital(root->right, newHospital);
        }
    }
    return root;
}

void showDoctorDetails() {
    char area[50];
    printf("\n==== Doctor & Hospital Details ====\n");
    printf("Enter the area name (Aftabnagar/Rampura/Banasree/Badda): ");
    fgets(area, 50, stdin);
    area[strcspn(area, "\n")] = '\0';

    printf("\n==== Hospitals in %s ====\n", area);
    searchHospitalsInArea(hospitalTree, area);
}

void searchHospitalsInArea(Hospital* root, const char* area) {
    if (root == NULL) return;

    // In-order traversal to find all hospitals in the area
    searchHospitalsInArea(root->left, area);

    if (strcmp(root->area, area) == 0) {
        printf("\nHospital Name: %s\n", root->name);
        printf("Address: %s\n", root->address);
        printf("Contact Number: %s\n", root->contact);
    }

    searchHospitalsInArea(root->right, area);
}

// ================== Main Menu ==================
void displayMainMenu() {
    printf("\n======= BhaloThako MediBot EWU =======\n");
    printf("1. Enter Patient Details\n");
    printf("2. Health Check\n");
    printf("3. Check Symptoms for Diseases\n");
    printf("4. Set Medicine Reminder\n");
    printf("5. Doctor & Hospital Details\n");
    printf("6. Exit\n");
}
