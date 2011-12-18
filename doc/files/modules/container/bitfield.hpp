namespace fcppt
{
namespace container
{
/// Contains fcppt::container::bitfield::basic and helper types/functions for it.
namespace bitfield
{
}
}
}

/**
\defgroup fcpptcontainerbitfield fcppt::container::bitfield
\ingroup fcpptcontainer
\brief A wrapper around a bitfield using an enum

\section bitfield_motivation Motivation

Sometimes you want an enumeration which can take multiple values at once - for
orthogonal options like "a person can be hungry and tired, not hungry and
tired, hungry and not tired or not hungry and not tired". An obvious solution
is using the bit representation of an enumeration:

\code
enum person_status
{
	hungry = 1,
	tired = 1 << 1,
	// insert more options here
};
\endcode

This is tiresome (!) to write and also a little dangerous since the underlying
type of an enumeration can only be an integral type. This means that you rely
upon the fact that you have enough bits available on the target machine --
which might not always be true. Think about a bit field which has more than 64
bits. fcppt::container::bitfield::basic is a template which remedies the
situation.

\section bitfield_requirements Requirements

fcppt::container::bitfield::basic takes as first template parameter an enum
<code>Enum</code> which satisfies the following requirements:

<ul>
<li>
	<code>Enum</code> shall be an enumeration type that doesn't contain any
	enumerators with explicit values.

	<strong>Example 1:</strong>
	\code
	enum my_enum { value1, value2, value3 };
	\endcode

	This is perfectly valid.

	<strong>Example 2:</strong>
	\code
	enum my_enum { value = 100 };
	\endcode

	This is <strong>NOT</strong> valid.
</li>
<li>
	<code>Size</code> shall be the number of enumerators defined in Enum.
	To achieve consistency you should define the enum's size within the
	enum itsself.  <strong>Example:</strong>
	\code
	enum my_enum { value1, value2, value3, _my_enum_size };

	typedef basic<my_enum,_my_enum_size> mybasic;
	\endcode
</li>
<li>
	<code>operator|(Enum,Enum)</code> shall not be declared!
</li>
<li>
	<code>std::numeric_limits<InternalType>::digits</code> shall be the
	number of bits usable in <code>InternalType</code>
</li>
</ul>

\section bitfield_example Example

Here's a small example on how bitfield is used:

\snippet doc/container_bitfield.cpp bitfield

As you can see, you can treat a bitfield like an integral type -- it has the
bitwise <code>operator&, operator|</code> and so on. But you can also treat it
like a <code>std::map<Enum,bool></code> and access elements like that. You
could even iterate through the bitfield like a container.
*/
