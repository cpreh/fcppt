//          Copyright Carl Philipp Reh 2009 - 2016.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_RECORD_ELEMENT_TO_LABEL_TPL_HPP_INCLUDED
#define FCPPT_RECORD_ELEMENT_TO_LABEL_TPL_HPP_INCLUDED

#include <fcppt/record/element_fwd.hpp>


namespace fcppt
{
namespace record
{

/**
\brief Extracts the type of an element and provides a type typedef to it

\ingroup fcpptrecord

\tparam Element Must be an \link fcppt::record::element\endlink.
*/
template<
	typename Element
>
struct element_to_label_tpl;

template<
	typename Label,
	typename Type
>
struct element_to_label_tpl<
	fcppt::record::element<
		Label,
		Type
	>
>
{
	typedef
	Label
	type;
};

}
}

#endif
