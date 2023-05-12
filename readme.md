Requires:

c++/cli support for v142 build tools.

and 

.net framework for visual studio 2019.

Otherwise will probably crash when opening in visual studio.

Executable file is available under /debug/


Might as well put the validation testing here.

Validation testing was performing by sticking all sorts of garbage in the text boxes for the software. Notably, this didn't break anything as .net was programmed with this in mind. What did break things was that the user can put in html tags in the paragraph and title boxes.
If the user does that everything breaks.
We had to add code to filter out any "<" ">" "&" symbols the user puts in those boxes. See symboltest.jpg