//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_ENABLE_SHARED_FROM_THIS_DECL_HPP_INCLUDED
#define FCPPT_ENABLE_SHARED_FROM_THIS_DECL_HPP_INCLUDED

#include <fcppt/enable_shared_from_this_fwd.hpp>
#include <fcppt/shared_ptr_fwd.hpp>
#include <fcppt/preprocessor/disable_gcc_warning.hpp>
#include <fcppt/preprocessor/pop_warning.hpp>
#include <fcppt/preprocessor/push_warning.hpp>
#include <fcppt/config/external_begin.hpp>
#include <memory>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{

FCPPT_PP_PUSH_WARNING
FCPPT_PP_DISABLE_GCC_WARNING(-Weffc++)

/**
\brief Allows an object to obtain a shared ptr to itself.

\ingroup fcpptsmartptr

Derive from this class to allow an object to obtain a shared ptr to itself.
*/
template<
	typename Type
>
class enable_shared_from_this
:
public
	std::enable_shared_from_this<
		Type
	>
{
	typedef
	std::enable_shared_from_this<
		Type
	>
	base;
protected:
	enable_shared_from_this();

	enable_shared_from_this(
		enable_shared_from_this const &
	);

	enable_shared_from_this &
	operator=(
		enable_shared_from_this const &
	);

	~enable_shared_from_this();

	fcppt::shared_ptr<
		Type
	>
	fcppt_shared_from_this();

	fcppt::shared_ptr<
		Type const
	>
	fcppt_shared_from_this() const;
};

FCPPT_PP_POP_WARNING

}

#endif
