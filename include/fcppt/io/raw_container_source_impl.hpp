//          Copyright Carl Philipp Reh 2009 - 2013.
//          Copyright Philipp Middendorf 2009 - 2013.
// Distributed under the Boost Software License, Version 1.0.
//    (See accompanying file LICENSE_1_0.txt or copy at
//          http://www.boost.org/LICENSE_1_0.txt)


#ifndef FCPPT_IO_RAW_CONTAINER_SOURCE_IMPL_HPP_INCLUDED
#define FCPPT_IO_RAW_CONTAINER_SOURCE_IMPL_HPP_INCLUDED

#include <fcppt/make_shared_ptr.hpp>
#include <fcppt/io/raw_container_source_decl.hpp>
#include <fcppt/config/external_begin.hpp>
#include <algorithm>
#include <iterator>
#include <fcppt/config/external_end.hpp>


template<typename Container>
template<typename Iterator>
fcppt::io::raw_container_source<Container>::raw_container_source(
	Iterator const _begin,
	Iterator const _end)
:
	chars_(
		fcppt::make_shared_ptr<container>(
			_begin,
			_end)),
	pos_(
		chars_->begin())
{
}

template<typename Container>
fcppt::io::raw_container_source<Container>::raw_container_source(
	raw_container_source const &_other
)
:
	chars_(
		_other.chars_
	),
	pos_(
		_other.pos_
	)
{
}

template<typename Container>
fcppt::io::raw_container_source<Container>::~raw_container_source()
{
}

template<typename Container>
std::streamsize
fcppt::io::raw_container_source<Container>::read(
	char *const _target,
	std::streamsize const _sz)
{
	difference_type const result =
		std::min(
			static_cast<
				difference_type
			>(
				_sz),
			std::distance(
				pos_,
				chars_->cend()));

	// EOF
	if (result == 0u)
		return -1;

	const_iterator const new_pos =
		std::next(
			pos_,
			result);

	std::copy(
		pos_,
		new_pos,
		_target);

	pos_ = new_pos;
	return result;
}

template<typename Container>
std::streampos
fcppt::io::raw_container_source<Container>::seek(
	boost::iostreams::stream_offset const _off,
	std::ios_base::seekdir const _way)
{
	difference_type const coff(
		static_cast<
			difference_type
		>(
			_off));

	switch (_way)
	{
		case std::ios_base::beg:
			pos_ =
				std::next(
					chars_->cbegin(),
					coff);
			break;
		case std::ios_base::cur:
			pos_ =
				std::next(
					pos_,
					coff);
			break;
		case std::ios_base::end:
			pos_ =
				std::prev(
					chars_->cend(),
					coff);
			break;
		default: break;
	}
	return
		static_cast<
			std::streampos
		>(
			std::distance(
				chars_->cbegin(),
				pos_));
}

#endif
