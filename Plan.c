/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Plan.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: go-donne <go-donne@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 19:37:56 by go-donne          #+#    #+#             */
/*   Updated: 2024/11/06 21:12:31 by go-donne         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

Components of program:

Makefile
Header file

.c files

I don't know what */*.h and */*.c mean (turn in files)



I will need to call Libft functions I have already implemented



Man pages for printf:

From command line, MacOS:


     The format string is reused as often as necessary to satisfy the arguments.  Any extra format specifications are evaluated with zero or the null string.

     Character escape sequences are in backslash notation as defined in the ANSI X3.159-1989 (``ANSI C89''), with extensions.  The characters and their meanings are as follows:

           \a      Write a <bell> character.
           \b      Write a <backspace> character.
           \c      Ignore remaining characters in this string.
           \f      Write a <form-feed> character.
           \n      Write a <new-line> character.
           \r      Write a <carriage return> character.
           \t      Write a <tab> character.
           \v      Write a <vertical tab> character.
           \'      Write a <single quote> character.
           \\      Write a backslash character.
           \num    Write a byte whose value is the 1-, 2-, or 3-digit octal number num.  Multibyte characters can be constructed using multiple \num sequences.

     Each format specification is introduced by the percent character (``%'').  The remainder of the format specification includes, in the following order:

     Zero or more of the following flags:

             #       A `#' character specifying that the value should be printed in an ``alternate form''.  For b, c, d, s and u formats, this option has no effect.  For the o formats the precision of the number is increased to force the first character of the output string to a zero.
                     For the x (X) format, a non-zero result has the string 0x (0X) prepended to it.  For a, A, e, E, f, F, g and G formats, the result will always contain a decimal point, even if no digits follow the point (normally, a decimal point only appears in the results of those
                     formats if a digit follows the decimal point).  For g and G formats, trailing zeros are not removed from the result as they would otherwise be;

             -       A minus sign `-' which specifies left adjustment of the output in the indicated field;

             +       A `+' character specifying that there should always be a sign placed before the number when using signed formats.

             ` '     A space specifying that a blank should be left before a positive number for a signed format.  A `+' overrides a space if both are used;

             0       A zero `0' character indicating that zero-padding should be used rather than blank-padding.  A `-' overrides a `0' if both are used;

     Field Width:
             An optional digit string specifying a field width; if the output string has fewer bytes than the field width it will be blank-padded on the left (or right, if the left-adjustment indicator has been given) to make up the field width (note that a leading zero is a flag, but an
             embedded zero is part of a field width);

     Precision:
             An optional period, `.', followed by an optional digit string giving a precision which specifies the number of digits to appear after the decimal point, for e and f formats, or the maximum number of bytes to be printed from a string; if the digit string is missing, the pre-
             cision is treated as zero;

     Format:
             A character which indicates the type of format to use (one of diouxXfFeEgGaAcsb).  The uppercase formats differ from their lowercase counterparts only in that the output of the former is entirely in uppercase.  The floating-point format specifiers (fFeEgGaA) may be prefixed
             by an L to request that additional precision be used, if available.

     A field width or precision may be `*' instead of a digit string.  In this case an argument supplies the field width or precision.

     The format characters and their meanings are:

     diouXx      The argument is printed as a signed decimal (d or i), unsigned octal, unsigned decimal, or unsigned hexadecimal (X or x), respectively.

     fF          The argument is printed in the style `[-]ddd.ddd' where the number of d's after the decimal point is equal to the precision specification for the argument.  If the precision is missing, 6 digits are given; if the precision is explicitly 0, no digits and no decimal point
                 are printed.  The values infinity and NaN are printed as `inf' and `nan', respectively.

     eE          The argument is printed in the style e `[-d.ddd+-dd]' where there is one digit before the decimal point and the number after is equal to the precision specification for the argument; when the precision is missing, 6 digits are produced.  The values infinity and NaN are
                 printed as `inf' and `nan', respectively.

     gG          The argument is printed in style f (F) or in style e (E) whichever gives full precision in minimum space.

     aA          The argument is printed in style `[-h.hhh+-pd]' where there is one digit before the hexadecimal point and the number after is equal to the precision specification for the argument; when the precision is missing, enough digits are produced to convey the argument's exact
                 double-precision floating-point representation.  The values infinity and NaN are printed as `inf' and `nan', respectively.

     c           The first byte of argument is printed.

     s           Bytes from the string argument are printed until the end is reached or until the number of bytes indicated by the precision specification is reached; however if the precision is 0 or missing, the string is printed entirely.

     b           As for s, but interpret character escapes in backslash notation in the string argument.  The permitted escape sequences are slightly different in that octal escapes are \0num instead of \num.

     n$          Allows reordering of the output according to argument.

:


Quite dense, quite a lot of new concepts / words.





Online:


CPP reference
https://en.cppreference.com/w/c/io/fprintf


Loads the data from the given locations, converts them to character string equivalents and writes the results to a variety of sinks/streams:

1) (printf) Writes the results to the output stream stdout.

format	-	pointer to a null-terminated byte string specifying how to interpret the data
...	-	arguments specifying data to print. If any argument after default argument promotions is not the type expected by the corresponding conversion specifier, or if there are fewer arguments than required by format, the behavior is undefined. If there are more arguments than required by format, the extraneous arguments are evaluated and ignored.


/*
A lot more information here, also on related functions:
fprintf, sprintf, snprintf, printf_s, fprintf_s, sprintf_s, snprintf_s
*/







# 1.0 Initial Orientation

### 1.0.1 Resource Hierarchy

Primary resources (simulating high-pressure conditions):

- Man pages from command line
- Official system documentation (UNIX, Linux, macOS)
- C language specification and standard library documentation

Secondary resources (for deeper understanding):

- Additional technical documentation
- Reference implementations
- Expert guidance (LLMs, mentors)
- Peer discussions and solutions (after initial personal work)

### 1.0.2 Core Principles

- Think from first principles
- Maintain systematic rigor
- Build deep, intuitive understanding
- Connect concepts across abstraction levels
- Consider security from the start


/*
I could read more about printf's functionality, but I need a clearer idea for an implementation approach
Can imagine using write: a lower-level function that can do the same thing: outputting (writing / printing) an output somewhere

How write & printf differ from my current knowledge:

printf "just prints" to the standard output...at least how I've used it
write can write to different file desciptors

I've used different format specifiers for different data types for printf
But with write, I've just passed an address to some data types & never had to be more exact about what they are


From the few C standard functions I've implemented (Libft project), I've seen how we work differently with different data types: integers, characters, a little on t_lists
How far down in the levels of abstraction are we with the write function, if we are to use it here? How am I to handle working with inputs of different data types? Can I draw from the insights I gained in Libft?

E.g. if printf: "Loads the data from the given locations, converts them to character string equivalents and writes the results to a variety of sinks/streams:"
it looks like I'll need some of my string manipulation functions. I also had some file desciptor functions
*/





1.1 Multi-Level Problem Analysis
