# Program Design Final Project
## Hospital System Visualizer
##### Team members: 周述君409410114、王信智409410116、劉哲嘉409410120、吳又成409515049

>MOTIVATION:In real life, people who suffer from COVID-19 swarm into hospitals. And we think it might be helpful if the nurses have a system to help them sort the patients quickly and distribute the patients to doctors efficiently. And the information of all the patients who have been to this hospital will be stored in the database, the user can get access to the information of the patient in the database if the same patient come to the hospital again in the future.

In this program, you can input the information by themself or by FILE INPUT, and these information will be used to build an array and be stored in the database. Then, user can choose to sort the array in order of age, weight or situation, whatever they want. After sorting the array, this array will be used to build a linked list called waiting list. The patients will be distributed to different clinics in the order of waiting list. And the patients who are in the clinic will form a queue called clinic list, which is used to keep track of the number of patients in the clinic.User can choose to output the database, waiting list or clinic list, it depends on which list the user wants to get access to.

* I/O Format
  |Input                  |Output                 |
  |-----------------------|:----------------------|
  |1                      |20 Allen PREGNANT 70    |
  |4                      |25 Zhejia SICK 60      |
  |20 Amos PANDEMIC 40     |18 Erica CARACCIDENT 50|
  |20 Allen PREGNANT 70   |20 Amos PANDEMIC 40     |
  |18 Erica CARACCIDENT 50|                       |
  |25 Zhejia SICK 60      |                       |
  |2                      |                       |
  |2                      |                       |
    
