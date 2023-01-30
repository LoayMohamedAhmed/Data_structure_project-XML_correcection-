# Data_structure_project-XML_correcection-

*hello guyes, **XML (Extensible Markup Language)** is one of the most famous formats for storing and sharing
information among different devices. Some text editors such as Sublime Text are able to parse
such files and do some basic operations. In this project, you will work on developing a GUI
(Graphical User Interface) based program to parse and visualize an XML file.

*But, in our system the XML file will represent users in a social network
Each user has id (unique), name, list of posts, list of followers.
Each post has text and list of topics, So we have added some cool featurs embedded with well defined interface (GUI) to make it easy to use

__**features**__

1.Checking the XML consistency: 

   The input XML may have inconsistencies like missing anyof the closing and opening tags or not matching tags so check error function can detect errors    with high percentage of accuracy and visually show them.
 ![Screenshot from 2023-01-30 14-07-42](https://user-images.githubusercontent.com/101834345/215473001-082e08b2-0851-4381-bbdb-ae1307e12d77.png)
   
2.The program is also able to solve errors discussed above.

3.Formatting (Prettifying) the XML:

  the XML file should be well formatted by keeping the indentation for each level, so prettifing function can handle it and you can take a look at its implementation.
  ![Screenshot from 2023-01-30 14-10-18](https://user-images.githubusercontent.com/101834345/215473331-bff4e910-6251-4b9a-ac8d-fcce387e9567.png)

4.Minifying the XML file: 

  Since spaces and newlines (\n) are actually characters that can increase the size of an XML document. This feature should aim at decreasing the size of an XML file (compressing it) by deleting the whitespaces and indentations.
  ![Screenshot from 2023-01-30 14-12-58](https://user-images.githubusercontent.com/101834345/215473923-f0d36569-d546-4ee4-82a5-2a07fe61c045.png)
