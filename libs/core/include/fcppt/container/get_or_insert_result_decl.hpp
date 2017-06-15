//          Copyright Carl Philipp Reh 2009 - 2017.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_CONTAINER_GET_OR_INSERT_RESULT_DECL_HPP_INCLUDED
#define FCPPT_CONTAINER_GET_OR_INSERT_RESULT_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/container/get_or_insert_result_fwd.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace container
{

/**
\brief The result type of \link fcppt::container::get_or_insert_with_result \endlink

\ingroup fcpptcontainer
*/
template<
	typename Reference
>
class get_or_insert_result
{
public:
	static_assert(
		std::is_reference<
			Reference
		>::value,
		"Reference must be a reference type"
	);

	get_or_insert_result(
		Reference,
		bool
	);

	template<
		typename Other
	>
	get_or_insert_result(
		get_or_insert_result<
			Other
		> const &
	);

	/**
	\brief A reference to the element in the container
	*/
	Reference
	element() const;

	/**
	\brief Tells if the element was inserted

	\return <code>true</code> if the element was inserted, <code>false</code> if it was found.
	*/
	bool
	inserted() const;
private:
	fcppt::reference<
		typename
		std::remove_reference<
			Reference
		>::type
	>
	reference_;

	bool inserted_;
};

}
}

#endif
