/**
\defgroup fcpptoptional fcppt::optional
\ingroup fcpptmain
\brief A class that makes values optional.

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref optional_motivation</li>
	<li>\ref optional_value</li>
	<li>\ref optional_reference</li>
	<li>\ref optional_design</li>
	<li>\ref optional_headers</li>
</ol>

</td>
</tr>
</table>

\section optional_motivation Motivation

Sometimes it is necessary to distinguish between having a value and having
none.
There are several ways that are often used to make this work:
<ul>
<li>Using a <em>special value</em> which indicates no value, for example
<code>static_cast<unsigned>(-1)</code></li>
<li>Using a pointer to a value and set the pointer to NULL to indicate no
value</li>
<li>Setting an additional bool flag</li>
</ul>

All of these have several shortcomings:
<ul>
<li>Special values might not be available, and on top of that they are very
error prone.</li>
<li>Pointers to temporaries that might vanish cannot be passed around. For
example a function returning a value cannot do so by a pointer.</li>
<li>Additional bool flags are cumbersome to handle and are error
prone as well.</li>
</ul>

An fcppt::optional instead is a wrapper around a value that can be absent.
Here is a small example.
\code
typedef fcppt::optional<
	unsigned
> optional_uint;

void
test_function(
	optional_uint opt
)
{
	// Test if opt is set
	if(
		opt.has_value()
	)
		// Output the value
		// This is undefined if has_value() == false
		std::cout << *opt << '\n';
}

// Prints nothing
test_function(
	optional_uint()
);

// Prints 3
test_function(
	optional_uint(3u)
);
\endcode

\section optional_value Values

If fcppt::optional<T> is used and T is not a reference type, the optional will
be an optional value. An optional value, as its name suggests, has value
semantics, meaning that it will copy the value. Therefore, T has to be
CopyConstructible and Assignable with the usual meanings. Here is a small
example:

\code
typedef fcppt::optional<
	unsigned
> optional_uint;

unsigned int1(5u);

// opt takes a copy of int1
optional_uint opt(int1);

int1 = 10u;

// The value of opt will still be 5u
assert(
	*opt != int1
);
\endcode

Optional values, denoted by fcppt::optional<T>, have some special semantics,
in contrast to optional references:
<ul>
<li>They can be assigned from an expression of type T const &.</li>
<li>They can be constructed from an fcppt::optional<T &> or an
fcppt::optional<T const &>. This has the same semantics as constructing a T
from a T & or T const & with the addition that has_value will be preserved.</li>
<li>They can also be assigned from an fcppt::optional<T &> or an
fcppt::optional<T const &> with the same semantics.</li>
<li>An optional value can be reset, using fcppt::optional<T>::reset. The
optional will have no value after that.</li>
<li>Their own constness determines if they can be modified which means if the
stored value is const and if the optional can be reset or assigned a new
value.</li>
</ul>

For optional references, see \ref optional_reference

\section optional_design Design

There is already <code>%boost::optional</code> so you might wonder why
fcppt provides its own optional type. It is actually quite similar to
<code>%boost::optional</code> in the sense that it stores optional values
by value and not by means of dynamically allocated memmory. This means
that an optional value is at least as big as its type it holds.
The key differences to <code>%boost::optional</code> are
<ul>
<li>fcppt::optional<T> uses alignment support from the compiler instead of
relying on the hacky <code>%boost::detail::aligned_storage</code></li>
<li>fcppt::optional doesn't have an implicit constructor.</li>
<li>fcppt::optional<T &> doesn't allow implicit conversions for assignment</li>
</ul>

\section optional_headers Header files

fcppt::optional is spread out across various header files.

<table>
<tr>
<th>Header file</th>
<th>Description</th>
</tr>
<tr>
<td><code>optional_fwd.hpp</code></td>
<td>Contains \link fcppt::optional optional's \endlink declaration.</td>
</tr>
<tr>
<td><code>optional_decl.hpp</code></td>
<td>Contains \link fcppt::optional optional's \endlink definition.</td>
</tr>
<tr>
<td><code>optional_impl.hpp</code></td>
<td>Contains the definition of \link fcppt::optional optional's \endlink member functions.</td>
</tr>
<tr>
<td><code>optional_comparison.hpp</code></td>
<td>Contains operator== and operator!=</td>
</tr>
<tr>
<td><code>dynamic_optional_cast.hpp</code></td>
<td>Contains \link fcppt::dynamic_optional_cast \endlink.</td>
</tr>
</table>
*/
