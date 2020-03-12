//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED
#define FCPPT_UNIQUE_PTR_DECL_HPP_INCLUDED

#include <fcppt/noncopyable.hpp>
#include <fcppt/unique_ptr_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

/**
\brief A simpler unique_ptr that shouldn't be used as a null pointer.

\ingroup fcpptsmartptr

<code>std::unique_ptr</code> can easily be used as a null pointer because it has a default constructor and also a reset function.
Null pointers should always be handled by optional references instead (see \ref fcpptoptional).
While it is not possible to completely forbid unique pointers that are null, this class makes it harder to do so.
Unique pointers that have been moved from may still be null because a unique pointer must track its ownership status.
Make sure not to access such pointers.
*/
template<
	typename Type,
	typename Deleter
>
class unique_ptr
{
	FCPPT_NONCOPYABLE(
		unique_ptr
	);
public:
	using
	element_type
	=
	Type;

	using
	pointer
	=
	element_type *;

	using
	deleter_type
	=
	Deleter;

	explicit
	unique_ptr(
		pointer
	)
	noexcept;

	unique_ptr(
		unique_ptr &&
	)
	noexcept;

	unique_ptr &
	operator=(
		unique_ptr &&
	)
	noexcept;

	~unique_ptr();

	std::add_lvalue_reference_t<
		Type
	>
	operator*() const
	noexcept;

	pointer
	operator->() const
	noexcept;

	pointer
	get_pointer() const
	noexcept;

	/**
	\brief Releases ownerhsip

	This can be used to move the pointer to another class that takes over
	ownership. Use this with extreme caution.
	*/
	pointer
	release_ownership()
	noexcept;
private:
	std::unique_ptr<
		Type,
		Deleter
	> impl_;
};

}

#endif
