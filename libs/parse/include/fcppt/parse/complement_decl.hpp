//          Copyright Carl Philipp Reh 2009 - 2018.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_PARSE_COMPLEMENT_DECL_HPP_INCLUDED
#define FCPPT_PARSE_COMPLEMENT_DECL_HPP_INCLUDED

#include <fcppt/reference_fwd.hpp>
#include <fcppt/unit_fwd.hpp>
#include <fcppt/parse/context_fwd.hpp>
#include <fcppt/parse/complement_fwd.hpp>
#include <fcppt/parse/state_fwd.hpp>
#include <fcppt/parse/result_fwd.hpp>
#include <fcppt/parse/result_of.hpp>
#include <fcppt/parse/detail/single_char.hpp>
#include <fcppt/type_traits/remove_cv_ref_t.hpp>
#include <fcppt/config/external_begin.hpp>
#include <type_traits>
#include <fcppt/config/external_end.hpp>


namespace fcppt
{
namespace parse
{

template<
	typename Parser
>
class complement
{
public:
	static_assert(
		std::is_same_v<
			fcppt::parse::result_of<
				Parser
			>,
			fcppt::unit
		>,
		"Complement parser can only be used with unit result type"
	);

	static_assert(
		fcppt::parse::detail::single_char<
			fcppt::type_traits::remove_cv_ref_t<
				Parser
			>
		>::value,
		"Complement parser can only be used with parsers that read a single character"
	);

	explicit
	complement(
		Parser &&
	);

	typedef
	fcppt::unit
	result_type;

	template<
		typename Ch,
		typename Skipper
	>
	fcppt::parse::result<
		result_type
	>
	parse(
		fcppt::reference<
			fcppt::parse::state<
				Ch
			>
		>,
		fcppt::parse::context<
			Skipper
		> const &
	) const;
private:
	Parser parser_;
};

}
}

#endif
