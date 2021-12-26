Data Structures and Algorithms
Assignment#2
Question#1:
In this question, you are going to build a movie database. The movie database will contain list of movies
along with the actors that worked in that particular movie. You are going to build this database using
Linked List data structure. First let us talk about the details about each node in the linked list. Your node
structure would contain the following things:
1) String (to store the name of the movie or an actor)
2) Pointer to the next node in the linked list.
3) Pointer to the node below the current node.
Data for the movie database has been provided to you in a file named “movie.txt”. Following is the
format of data in the movie file:
Movie name 1
Actor name 1
Actor name 2
Actor name 3
#
Movie name 2
Actor name 4
Actor name 5
Actor name 2
Actor name 6
#
.
.

(After the every list of actors we have # sign in the next line).
The first line in the “movie.txt” would contain the name of a particular movie. You have to store this
name in the string of the node (details given above). For the next few lines, you will have list of actors
who have worked in that particular movie. Each single line would contain name of only one actor. As
soon as the list of actors end, you will have a # symbol. In the next line, you will have another movie
name (which will always be unique) followed by its list of actors and then again a # sign.
![image](https://user-images.githubusercontent.com/75989502/147407322-8d07e1ee-4e28-44d3-adff-4bb803dbeee2.png)

For the linked list, you need to arrange the file information in such a way that each parent node of the
linked list contains name of the movies. Each parent node has two pointers. The “next” pointer points to
another parent node which has name of some other movie in it. The “below” pointer points to the actor
who has worked in the movie. So essentially, the first row of the linked list (containing parent nodes) has
list of all the movies in it. Below each movie node is the list of all the actors that have worked in that
movie.
a) Search by movie name
If the user enters a movie name then you will have to display all the actors list against that movie by
performing search in the linked list.
IMPORTANT NOTE:
Since File I/O is a very costly operation, you are only allowed to traverse the file once.
