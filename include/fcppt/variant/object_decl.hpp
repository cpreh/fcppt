//          Copyright Carl Philipp Reh 2009 - 2011.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED
#define FCPPT_VARIANT_OBJECT_DECL_HPP_INCLUDED

#include <fcppt/alignment/array.hpp>
#include <fcppt/mpl/max_value.hpp>
#include <fcppt/variant/object_fwd.hpp>
#include <fcppt/variant/raw_type.hpp>
#include <fcppt/variant/size_type.hpp>
#include <fcppt/config/external_begin.hpp>
#include <boost/mpl/placeholders.hpp>
#include <boost/mpl/size.hpp>
#include <boost/mpl/sizeof.hpp>
#include <boost/type_traits/alignment_of.hpp>
#include <typeinfo>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace variant
{

/**
\brief A class that can hold any object from a fixed set of types

\ingroup fcpptvariant

\tparam Types An MPL sequence of types that must be CopyConstructible,
Assignable and complete.

<table id="toc">
<tr>
<td>

<ol>
	<li>\ref variant_motivation</li>
	<li>\ref variant_visitation</li>
	<li>\ref variant_recursive</li>
	<li>\ref variant_headers</li>
</ol>

</td>
</tr>
</table>

\section variant_motivation Motivation

It might be necessary to store objects of different types in a variable.
C++ has so called unions which can do that. However, a union has several
disadvantages:
<ul>

<li>It doesn't know which type of object it actually holds. This can also be
nothing at all when the union has not been initialized.</li>

<li>If you access the wrong type of the union, then the behaviour is
undefined.</li>

<li>A union also doesn't know how to call constructors or destructors (this has
been relaxed in C++11 but it is still cumbersome). So you are very restricted
with the types of objects you can store in them.</li>

</ul>

\code
union int_or_float
{
	int i;
	float f;
};

int_or_float var;

// Undefined behaviour because the union doesn't store anything
std::cout << var.i << '\n';

// Ok, but doesn't track that the type is int
var.i = 42;

// Undefined behaviour because the union stores an int
std::cout << var.f << '\n';

void
print(
	int_or_float x
)
{
	// how do we know which type of object is stored?
}

print(var);

// Doesn't work
union string_or_int
{
	std::string s;
	int i;
};
\endcode

For a union, the stored type has to be tracked somehow or must be inferred from
the environment where the union is used. This is cumbersome to do, but it can
be done. Taking our previously defined int_or_float, it might look something
like this.

\code
enum stored_type
{
	int_,
	float_
};

int_or_float var;

stored_type type;

var.i = 42;
type = int_;

void
print(
	int_or_float x,
	stored_type t
)
{
	switch(t)
	{
	case int_:
		std::cout << x.i << '\n';
	case float_:
		std::cout << x.f << '\n';
	}
}

print(
	var,
	type
);
\endcode

In order to fix the aforementioned problems, fcppt::variant's approach is very
different from a union.

<ul>

<li>It knows which type it holds, which can be queried at any time.</li>

<li>It is not default constructible which doesn't make any sense for
variants.</li>

<li>If the wrong type of the variant is accessed, you will get an
exception.</li>

<li>It calls constructors, assignment operators and destructors as needed.</li>

</ul>

The above example can be rewritten as follows:

\code
// Note that an MPL sequence is used here to describe which types the variant
// can hold
typedef fcppt::variant::object<
	boost::mpl::vector2<
		std::string,
		int
	>
> string_or_int;

void
print(
	string_or_int x
)
{
	// fcppt::variant::holds_type queries if the type is held by the
	// variant
	if(
		fcppt::variant::holds_type<std::string>(x)
	)
		std::cout << x.get<std::string>() << '\n';
	else if(
		fcppt::variant::holds_type<int>(x)
	)
		std::cout << x.get<int>() << '\n';
}

string_or_int var(
	std::string(
		"Hello World"
	)
);

print(
	var
);
\endcode

\section variant_visitation Visitation

Given the <code>string_or_int</code> variant it is already cumbersome to print
it. If there were more cases (which means more types that the variant can hold)
it would be even more cumbersome.

In order to solve this, there is a mechanism called visitation. A class that
can visit a set of types is called a visitor. Instead of focusing on making the
set of types extensible, visitation aims to make the set of operations on them
extensible. The downside of this is that the visitor has to know about all
types in the set. Luckily, that's better than it sounds. A visitor can employ
all sorts of C++ template mechanisms to make this easier.

To define a visitor, it must have function call operators so that for all types
in the set exactly one of them matches. The function call operators must also
be <code>const</code>. The visitor must have a typedef <code>result_type</code>
which must be the result type of every function call operator it provides.

\code
struct print_visitor
{
	typedef void result_type;

	result_type
	operator()(
		std::string s
	) const
	{
		std::cout << s << '\n';
	}

	result_type
	operator()(
		int i
	) const
	{
		std::cout << i << '\n';
	}
};

// prints "Hello World"
fcppt::variant::apply_unary(
	print_visitor(),
	string_or_int(
		std::string(
			"Hello World"
		)
	)
);

// prints 42
fcppt::variant::apply_unary(
	print_visitor(),
	string_or_int(
		42
	)
);
\endcode

In this case, it is possible to employ templates to make the visitor a lot
easier.

\code
struct print_visitor2
{
	typedef void result_type;

	template<
		typename T
	>
	result_type
	operator()(
		T const &arg
	) const
	{
		std::cout << arg << '\n';
	}
};
\endcode

It is often advisable to make a visitor as generic as possible. enable_if
combined with type traits can also help.

fcppt::variant::apply_binary and fcppt::variant::apply_ternary are also
provided. These can be used to visit two or three variants at the same time.
In this case, the operator() takes two or three arguments, respectively.

Here is a small example for defining a binary visitor:

\snippet variant.cpp variant_binary_visitor
\snippet variant.cpp variant_binary_visitation

\section variant_recursive Recursive data structures

A problem arises when a variant can hold a data structure that holds the yet to
be defined variant itself. To break the cycle, such a data structure, called
<code>wrapper</code> here, must be forward declared and passed as a
<code>fcppt::variant::recursive<wrapper></code> to the variant. This is
necessary because the variant can only use complete types and
fcppt::variant::recursive is always complete. The variant itself will act as if
the recursive wrapper isn't there, which means that the type used with
fcppt::variant::object::get as well as the argument type passed for a
visitation will be <code>wrapper</code> and not
<code>fcppt::variant::recursive<wrapper></code>.

The following example shows how to declare such a recursive variant:

\snippet recursive_variant.cpp variant_recursive_declaration

The variant can hold <code>wrapper</code> which contains a variant itself.

\snippet recursive_variant.cpp variant_recursive_construction

\section variant_headers Header files
<table>
<tr>
<th>Header file</th>
<th>Description</th>
</tr>
<tr>
<td><code>object_fwd.hpp</code></td>
<td>Contains \link fcppt::variant::object variants's \endlink declaration.</td>
</tr>
<tr>
<td><code>object_decl.hpp</code></td>
<td>Contains \link fcppt::variant::object variant's \endlink definition.</td>
</tr>
<tr>
<td><code>object_impl.hpp</code></td>
<td>Contains the definition of \link fcppt::variant::object variants's \endlink member functions.</td>
</tr>
<tr>
<td><code>apply_unary.hpp</code></td>
<td>Contains fcppt::variant::apply_unary for unary visitation</td>
</tr>
<tr>
<td><code>apply_binary.hpp</code></td>
<td>Contains fcppt::variant::apply_binary for binary visitation</td>
</tr>
<tr>
<td><code>apply_ternary.hpp</code></td>
<td>Contains fcppt::variant::apply_ternary for ternary visitation</td>
</tr>
<tr>
<td><code>equal.hpp</code></td>
<td>Contains operator==</td>
</tr>
<tr>
<td><code>exception.hpp</code></td>
<td>Contains fcppt::variant::exception, the base class for every variant exception</td>
</tr>
<tr>
<td><code>exception.hpp</code></td>
<td>Contains fcppt::variant::exception, the base class for every variant exception</td>
</tr>
<tr>
<td><code>get.hpp</code></td>
<td>Contains a free get function which does the same thing as the get member function</td>
</tr>
<tr>
<td><code>holds_type.hpp</code></td>
<td>Contains the fcppt::variant::holds_type function to check if a type is held by the variant</td>
</tr>
<tr>
<td><code>invalid_get.hpp</code></td>
<td>Contains fcppt::variant::invalid_get, which might be thrown by get</td>
</tr>
<tr>
<td><code>not_equal.hpp</code></td>
<td>Contains operator!=</td>
</tr>
<tr>
<td><code>output.hpp</code></td>
<td>Contains operator<< for output</td>
</tr>
<tr>
<td><code>recursive.hpp</code></td>
<td>Contains the recursive tag struct</td>
</tr>
</table>
*/
template<
	typename Types
>
class object
{
public:
	/**
	\brief An mpl sequence of the possible types
	*/
	typedef Types types;

	/**
	\brief Constructs the variant from a value

	Constructs the variant from \a value. This constructor is intentionally
	not explicit.

	\tparam U Must be a type or a type contained in an
	fcppt::variant::recursive among <code>types</code>

	\param value The value to construct the variant from

	\post <code>fcppt::variant::holds_type<U>(*this)</code> is true
	*/
	template<
		typename U
	>
	object(
		U const &value
	);

	/**
	\brief Copy constructs a variant

	Copy constructs the value held by \a other into the variant.

	\param other The variant to copy from

	\post <code>this->type_index() == other.type_index()</code>
	*/
	object(
		object const &other
	);

	/**
	\brief Assigns a new value to the variant

	Assigns \a value to the variant. Calls the assignment operator of the
	held type when possible.

	\tparam U Must be a type or a type contained in an
	fcppt::variant::recursive among <code>types</code>

	\param value The value to assign the variant from

	\post <code>fcppt::variant::holds_type<U>(*this)</code> is true
	*/
	template<
		typename U
	>
	object &
	operator=(
		U const &value
	);

	/**
	\brief Assigns a variant

	Assigns the value from \a other to the variant. Calls the assignment
	operator of the held type when possible.

	\param other The variant to assign from

	\post <code>this->type_index() == other.type_index()</code>
	*/
	object &
	operator=(
		object const &other
	);

	/**
	\brief Destroys the variant

	Calls the destructor of the held value.
	*/
	~object();

	/**
	\brief Returns a const reference to the held type

	If <code>fcppt::variant::holds_type<U>(*this)</code> is true, then a
	const reference to currently held value is be returned.

	\tparam U Must be a type or a type contained in an
	fcppt::variant::recursive among <code>types</code>

	\throw fcppt::variant::invalid_get if
	<code>fcppt::variant::holds_type<U>(*this)</code> is false
	*/
	template<
		typename U
	>
	U const &
	get() const;

	/**
	\brief Returns a reference to the held type

	If <code>fcppt::variant::holds_type<U>(*this)</code> is true, then a
	reference to currently held value is be returned.

	\tparam U Must be a type or a type contained in an
	fcppt::variant::recursive among <code>types</code>

	\throw fcppt::variant::invalid_get if
	<code>fcppt::variant::holds_type<U>(*this)</code> is false
	*/
	template<
		typename U
	>
	U &
	get();

	/**
	\brief Returns a const reference to the held type without any checks

	If <code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is true, a const reference to currently held
	value is be returned.

	Note that this function does not transform recursive types, they will
	be returned as is.

	\tparam U Must be a type among <code>types</code>

	\warning The behaviour is undefined if
	<code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is false.
	*/
	template<
		typename U
	>
	U const &
	get_raw() const;

	/**
	\brief Returns a reference to the held type without any checks

	If <code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is true, a reference to currently held value
	is be returned.

	Note that this function does not transform recursive types, they will
	be returned as is.

	\tparam U Must be a type among <code>types</code>

	\warning The behaviour is undefined if
	<code>fcppt::mpl::index_of<types, U>::value ==
	this->type_index()</code> is false.
	*/
	template<
		typename U
	>
	U &
	get_raw();

	/**
	\brief Returns an <code>std::%type_info</code> of the held type
	*/
	std::type_info const &
	type() const;

	/**
	\brief Returns the index of the held type

	\return A runtime index into <code>types</code> of the held type.
	*/
	variant::size_type
	type_index() const;
private:
	template<
		typename U
	>
	void
	construct(
		U const &
	);

	void
	destroy();

	static variant::size_type const elements =
		boost::mpl::size<
			Types
		>::value
	;

	typedef typename alignment::array<
		variant::raw_type,
		mpl::max_value<
			Types,
			boost::mpl::sizeof_<
				boost::mpl::_1
			>
		>::value,
		mpl::max_value<
			Types,
			boost::alignment_of<
				boost::mpl::_1
			>
		>::value
	>::type storage_type;

	storage_type storage_;

	variant::size_type index_;

	void *data_;
};

}
}

#endif
