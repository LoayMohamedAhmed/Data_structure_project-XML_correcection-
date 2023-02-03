# Data_structure_project-XML_correcection-

* hello guyes, **XML (Extensible Markup Language)** is one of the most famous formats for storing and sharing
information among different devices. Some text editors such as Sublime Text are able to parse
such files and do some basic operations. In this project, you will work on developing a GUI
(Graphical User Interface) based program to parse and visualize an XML file.

* But, in our system the XML file will represent users in a social network
Each user has id (unique), name, list of posts, list of followers.
Each post has text and list of topics, So we have added some cool featurs embedded with well defined interface (GUI) to make it easy to use

<h2>note</h2>
* our ripo is devided into two main parts the first one GUI codes using qt and the second one is concel interface codes.
 
* programming language: C++.

<h2> features </h2>

<h3> 1. Checking the XML consistency: </h3>

   The input XML may have inconsistencies like missing anyof the closing and opening tags or not matching tags so check error function can detect errors    with high percentage of accuracy and visually show them.
 ![Screenshot from 2023-01-30 14-07-42](https://user-images.githubusercontent.com/101834345/215473001-082e08b2-0851-4381-bbdb-ae1307e12d77.png)
   
<h3> 2.The program is also able to solve errors discussed above. </h3>

<h3> 3.Formatting (Prettifying) the XML: </h3>

  the XML file should be well formatted by keeping the indentation for each level, so prettifing function can handle it and you can take a look at its implementation.
  ![Screenshot from 2023-01-30 14-10-18](https://user-images.githubusercontent.com/101834345/215473331-bff4e910-6251-4b9a-ac8d-fcce387e9567.png)

<h3> 4.Minifying the XML file: </h3>

  Since spaces and newlines (\n) are actually characters that can increase the size of an XML document. This feature should aim at decreasing the size of an XML file (compressing it) by deleting the whitespaces and indentations.
  !![Screenshot from 2023-02-03 14-00-20](https://user-images.githubusercontent.com/101834345/216598518-44686267-df1e-4f19-bb6a-ff7f988ccc9d.png)


<h3> 5.Converting XML to JSON:</h3>

JSON (Javascript Object Notation) is another format that is used
to represent data. It’s helpful to convert the XML into JSON, especially when using
javascript as there’s tons of libraries and tools that use json notation.

![Screenshot from 2023-02-03 13-57-56](https://user-images.githubusercontent.com/101834345/216598144-9d59d516-3d25-4e19-b4a2-74afc33d8129.png)


<h3> 6.representing the users data using the graph data structure: </h3>

the XML file will represent the users data in a social network (their posts, followers, ...etc).
The user data is his id (unique across the network), name, list of his posts and followers. So our sofware can represent the relation between the followers using the graph data structure as it will be very helpful for the network analysis.

![Screenshot_from_2023-02-03_14-27-19-removebg-preview](https://user-images.githubusercontent.com/101834345/216603827-1c623c40-c71f-421b-8e91-588725c87c17.png)

<h3>7.Network analysis: </h3>

our software can extract some important data like:
* who is the most influencer user (has the most followers)
* who is the most active user (connected to lots of users)
* the mutual followers between 2 users
* for each user, suggest a list of users to follow (the followers of his followers)

<h3> Post search:</h3>

our software can also provide a a post search feature by using specific word either from body or the topic of the post and return the post with the author name
