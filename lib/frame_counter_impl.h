/* -*- c++ -*- */
/*
 * Copyright 2023 Daniel Estevez <daniel@destevez.net>.
 *
 * SPDX-License-Identifier: GPL-3.0-or-later
 */

#ifndef INCLUDED_DVBGSE_FRAME_COUNTER_IMPL_H
#define INCLUDED_DVBGSE_FRAME_COUNTER_IMPL_H

#include <dvbgse/frame_counter.h>

namespace gr {
namespace dvbgse {

class frame_counter_impl : public frame_counter
{
private:
    const size_t d_itemsize;
    const size_t d_frame_size;
    const pmt::pmt_t d_frame_message;
    size_t d_nitems;

public:
    frame_counter_impl(size_t itemsize, size_t frame_size);
    ~frame_counter_impl() override;

    int work(int noutput_items,
             gr_vector_const_void_star& input_items,
             gr_vector_void_star& output_items) override;
};

} // namespace dvbgse
} // namespace gr

#endif /* INCLUDED_DVBGSE_FRAME_COUNTER_IMPL_H */
