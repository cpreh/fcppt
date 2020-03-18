//          Copyright Carl Philipp Reh 2009 - 2020.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_CONTEXT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_CONTEXT_DECL_HPP_INCLUDED

#include <fcppt/reference_impl.hpp>
#include <fcppt/unit.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Skipper
>
class context
{
public:
	static_assert(
		std::is_same_v<
			fcppt::parse::result_of<
				Skipper
			>,
			fcppt::unit
		>,
		"Skippers must return fcppt::unit"
	);

	using
	skipper_ref
	=
	fcppt::reference<
		Skipper const
	>;

	explicit
	context(
		skipper_ref
	);

	skipper_ref
	skipper() const;
private:
	skipper_ref skipper_;
};

}
}

#endif
