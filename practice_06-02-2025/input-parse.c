#include<stdio.h>
#include<stdlib.h>

enum status
{
    completed = 0,
    stopped,
    processed
};

struct job
{
    int id;
    enum status s;
    struct job *next;
};

struct job* createJob(int id, enum status s) 
{
    struct job *newJob = (struct job*)malloc(sizeof(struct job));
    newJob->id = id;
    newJob->s = s;
    newJob->next = NULL;
    return newJob;
}

void updateStatus(struct job *job, enum status newStatus) 
{
    job->s = newStatus;
}

const char* getStatusString(enum status s) 
{
    switch(s) 
    {
        case 0: return "Completed";
        case 1: return "Stopped";
        case 2: return "Processed";
        default: return "Unknown";
    }
}

void printJobs(struct job *head) 
{
    struct job *current = head;
    while (current != NULL) 
    {
        printf("Job ID: %d, Status: %s\n", current->id, getStatusString(current->s));
        current = current->next;
    }
}

int main() 
{
    struct job *head = createJob(1, 0); 
    struct job *second = createJob(2, 1); 
    struct job *third = createJob(3, 2); 
    
    head->next = second;
    second->next = third;

    printJobs(head);
    
    updateStatus(second, completed); 

    printf("\nUpdated Job List:\n");
    printJobs(head);

    return 0;
}
