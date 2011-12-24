/**
\defgroup fcpptexport Export
\ingroup fcpptmain
\brief Macros related to library visibility

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref exports_introduction</li>
	<li>\ref exports_library</li>
	<li>\ref exports_vtable</li>
	<li>\ref exports_list</li>
	<li>\ref exports_compiler</li>
	<li>\ref exports_headers</li>
</ol>

</td>
</tr>
</table>

\section exports_introduction Introduction

When building a library, several platforms have different notions of
<em>library visibility</em> that the library author has to consider. A symbol
(like a function or global object) can be hidden in the library or it can be
made public for other libraries or programs to use (for POSIX systems it is
slightly more complex, but the two mentioned cases are the ones that really
matter). Furthermore the library author has to specify whether a symbol is
currently being exported or imported (because some platforms like Windows need
this).

\note
Although every symbol can be made public under a POSIX system by default, this
is still not recommended, because you have to specify the visibility for
Windows anyway and libraries with only public symbols tend to have an
unnecessarly large interface.

\section exports_library Defining library interfaces

Several macros are provided to make a symbol public. Because it is necessary to
specify whether a symbol is currently imported or exported, some additional
work needs to be done by the library author and the build system to ensure that
this is always correctly specified. The common way to do this is to define some
kind of macro when the library is being built, which means the symbols are
currently exported. This macro will not be defined in all other cases, which
means the symbols are currently imported.

In the following example the macro <code>MYLIB_EXPORTS</code> is defined
by the build system if the library is currently begin built. This macro
is used to define <code>MYLIB_SYMBOL</code> to either \link FCPPT_EXPORT_SYMBOL \endlink
or \link FCPPT_IMPORT_SYMBOL \endlink.

\snippet visibility.cpp visibility_macros

<code>MYLIB_SYMBOL</code> can then be used to export a function.

\snippet visibility.cpp visibility_export_function

The definition of the function doesn't need anything special.

\snippet visibility.cpp visibility_define_function

\section exports_vtable Exporting a vtable of a class

If a class's vtable needs to be exported, a special macro \link
FCPPT_CLASS_SYMBOL \endlink must be used. This macro doesn't need to change
whether the vtable is currently imported or exported.

\see \link FCPPT_CLASS_SYMBOL \endlink for a detailed explanation

\snippet visibility.cpp visibility_export_vtable1
\snippet visibility.cpp visibility_export_vtable2

\section exports_list List of things to export

Generally, every object with external linkage must be exported.
This includes:

<ul>

<li>Functions (free or in a class), constructors and destructors which are
defined inside the library need a conditional symbol like
<code>MYLIB_SYMBOL</code> at their declaration, and nothing special at their
definition.</li>

<li>Objects with external linkage defined inside the library are handled like
functions.
\snippet visibility.cpp visibility_export_object

\snippet visibility.cpp visibility_define_object
</li>

<li>Explicitly instantiated templates are special because they not only need
what their non template variants would need, but they also need an \link
FCPPT_EXPORT_SYMBOL \endlink at their explicit instantiation. In the following
example, a templated function is explicitly instantiated and exported. The
function delaration needs a conditional symbol like <code>MYLIB_SYMBOL</code>
because a normal function would also need it.

\snippet visibility.cpp visibility_export_template

The explicit instantiation needs an additional \link FCPPT_EXPORT_SYMBOL
\endlink. It is important that this comes after the <code>template</code>
keyword but before the rest of the explicit instantiation.

\snippet visibility.cpp visibility_define_template
</li>
</ul>

\section exports_compiler Compiler specific usage

Library visibility is only useful if a shared library is being built and if the
symbols of the shared library are hidden by default. Here is some advice
how to use different build systems:
<ul>

<li>For gcc and clang, you should use the option
<code>-fvisibility=hidden</code>. Only then will all the symbols be hidden by
default, so that making symbols public actually does anything.</li>

<li>VC++ can only use public symbols when building a DLL. If you want to build
a static library instead, you should simply define your conditional symbol as
nothing.
\code
#if defined(MYLIB_STATIC)
#define MYLIB_SYMBOL
#elif defined(MYLIB_EXPORTS)
// ...
#endif
\endcode
</li>

</ul>

\section exports_headers Header files
<table>
<tr>
<th>Header file</th>
<th>Description</th>
</tr>
<tr>
<td><code>export_symbol.hpp</code></td>
<td>Contains \link FCPPT_EXPORT_SYMBOL \endlink.</td>
</tr>
<tr>
<td><code>import_symbol.hpp</code></td>
<td>Contains \link FCPPT_IMPORT_SYMBOL \endlink.</td>
</tr>
<tr>
<td><code>class_symbol.hpp</code></td>
<td>Contains \link FCPPT_CLASS_SYMBOL \endlink.</td>
</tr>
</table>

*/
