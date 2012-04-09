fcppt
=====

About
-----

<a href="http://boost.org">Boost</a> already is a very useful general purpose
library. If you use C++ without boost, the need for something that is already
provided by it will soon arise. However, boost is not perfect (and fcppt isn't
either). The need for something that isn't provided by boost might
arise, too, and there are even some things I consider not done "well" in boost.
Freundlich's C++ toolkit (from now on shortened to fcppt) tries to fill in some
gaps left by boost and even implements some replacements for a few boost
components.

Top-level module list
-----------

<table>
	<tr>
		<th>Module name</th>
		<th>Description</th>
	</tr>
	<tr>
		<td>fcppt.alignment</td>
		<td>Typedef structs and macros to specify alignment.</td>
	</tr>
	<tr>
		<td>fcppt.assert</td>
		<td>Macros and functions for assertions.</td>
	</tr>
	<tr>
		<td>fcppt.assign</td>
		<td>A replacement for boost::assign </td>
	</tr>
	<tr>
		<td>fcppt.casts</td>
		<td>Cast helpers which provide more type information or do additional checks.</td>
	</tr>
	<tr>
		<td>fcppt.container</td>
		<td>Various containers complementing the standard library and boost.</td>
	</tr>
	<tr>
		<td>fcppt.endianness</td>
		<td>Functions to convert and query endianness. </td>
	</tr>
	<tr>
		<td>fcppt.export</td>
		<td>Macros related to library visibility. </td>
	</tr>
	<tr>
		<td>fcppt.filesystem</td>
		<td>Helper functions for boost::filesystem.</td>
	</tr>
	<tr>
		<td>fcppt.io</td>
		<td>IO-related typedefs and functions. </td>
	</tr>
	<tr>
		<td>fcppt.log</td>
		<td>Logging classes and functions. </td>
	</tr>
	<tr>
		<td>fcppt.math</td>
		<td>Provides classes for matrices, vectors, boxes, as well as general-purpose math functions.</td>
	</tr>
	<tr>
		<td>fcppt.mpl</td>
		<td>MPL related helper functions and metafunctions. </td>
	</tr>
	<tr>
		<td>fcppt.optional</td>
		<td>A class that makes values optional. </td>
	</tr>
	<tr>
		<td>fcppt.preprocessor</td>
		<td>Macros for controlling warnings and printing message. </td>
	</tr>
	<tr>
		<td>fcppt.random</td>
		<td> Random number generators and distributions. </td>
	</tr>
	<tr>
		<td>fcppt.ref</td>
		<td>Reference wrappers. </td>
	</tr>
	<tr>
		<td>fcppt.signal</td>
		<td>An implementation of a managed signals and slots system (replacement for boost's signals). </td>
	</tr>
	<tr>
		<td>fcppt.smart_pointers</td>
		<td>Smart pointers and their utilities. </td>
	</tr>
	<tr>
		<td>fcppt.string</td>
		<td>String-related functions and types. </td>
	</tr>
	<tr>
		<td>fcppt.strong_typedef</td>
		<td>The strong typedef class and helper macros. </td>
	</tr>
	<tr>
		<td>fcppt.thread</td>
		<td>Wrappers around boost.thread following std::thread semantics. </td>
	</tr>
	<tr>
		<td>fcppt.time</td>
		<td>Time query, formatting and sleep utilities. </td>
	</tr>
	<tr>
		<td>fcppt.type_traits</td>
		<td>Some additional type traits. </td>
	</tr>
	<tr>
		<td>fcppt.variant</td>
		<td>A class that can hold any object from a fixed set of types. </td>
	</tr>
	<tr>
		<td>fcppt.various</td>
		<td>Smaller macros and functions like <code>FCPPT_NONCOPYABLE</code>, <code>FCPPT_SAFE_BOOL</code>, <code>FCPPT_ASSERT_COMPLETE</code>, <code>fcppt::null_ptr_t</code></td>
	</tr>
</table>

Requirements
------------

fcppt needs the following at build time:

- >= cmake-2.6
- >= boost-1.47
- A compiler that implements tr1

To build the documentation, you also need >= doxygen-1.7.5.

Tested platforms
--------------------------------

- gcc-4.5.3 (Gentoo Linux, x86)
- gcc-4.6.3 (Gentoo Linux, amd64)
- gcc-4.7.0 (Gentoo Linux, amd64)
- clang-3.0 (Gentoo Linux, amd64)
- Apple clang 3.0 (MacOS)
- VC++ 2010 SP1 (Windows 7 64 Bit)

Building and installation
-------------------------

The official fcppt installation guide can be found in the <a
href="http://fcppt.org/d3/d36/requirements_download_installation.html">official
documentation</a>.

More information
----------------

Check out our homepage at <a href="http://fcppt.org">fcppt.org</a> for more information.

Contact
-------

You can contact us via our IRC channel

`#sge-sanguis`

at

`irc.freenode.net`
