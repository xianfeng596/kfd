/*
 * Copyright (c) 2023 Félix Poulin-Bélanger. All rights reserved.
 */

#ifndef dynamic_info_h
#define dynamic_info_h

struct dynamic_info {
    bool kread_kqueue_workloop_ctl_supported;
    bool krkw_iosurface_supported;
    bool perf_supported;
    u64 kernelcache__static_base;
    // struct proc
    u64 proc__p_list__le_prev;
    u64 proc__p_list__le_next;
    u64 proc__task;
    u64 proc__p_pid;
    u64 proc__p_fd__fd_ofiles;
    u64 proc__object_size;
    // struct task
    u64 task__map;
    // struct vm_map
    u64 vm_map__hdr_links_prev;
    u64 vm_map__hdr_links_next;
    u64 vm_map__min_offset;
    u64 vm_map__max_offset;
    u64 vm_map__hdr_nentries;
    u64 vm_map__hdr_nentries_u64;
    u64 vm_map__hdr_rb_head_store_rbh_root;
    u64 vm_map__pmap;
    u64 vm_map__hint;
    u64 vm_map__hole_hint;
    u64 vm_map__holes_list;
    u64 vm_map__object_size;
    // struct thread
    u64 thread__thread_id;
    // struct IOSurface
    u64 IOSurface__isa;
    u64 IOSurface__pixelFormat;
    u64 IOSurface__allocSize;
    u64 IOSurface__useCountPtr;
    u64 IOSurface__indexedTimestampPtr;
    u64 IOSurface__readDisplacement;
    // kernelcache static addresses (IOSurface)
    u64 kernelcache__allproc;
    // kernelcache static addresses (perf)
    u64 kernelcache__cdevsw;                          // "spec_open type" or "Can't mark ptc as kqueue ok"
    u64 kernelcache__gPhysBase;                       // "%s: illegal PA: 0x%llx; phys base 0x%llx, size 0x%llx"
    u64 kernelcache__gPhysSize;                       // (gPhysBase + 0x8)
    u64 kernelcache__gVirtBase;                       // "%s: illegal PA: 0x%llx; phys base 0x%llx, size 0x%llx"
    u64 kernelcache__perfmon_dev_open;                // "perfmon: attempt to open unsupported source: 0x%x"
    u64 kernelcache__perfmon_devices;                 // "perfmon: %s: devfs_make_node_clone failed"
    u64 kernelcache__ptov_table;                      // "%s: illegal PA: 0x%llx; phys base 0x%llx, size 0x%llx"
    u64 kernelcache__vn_kqfilter;                     // "Invalid knote filter on a vnode!"
    // address translation
    u64 device__T1SZ_BOOT;
    u64 device__ARM_TT_L1_INDEX_MASK;
};

const struct dynamic_info kern_versions[] = {
    // iOS 15.7.6 - iPhone 6s
    {
        .kread_kqueue_workloop_ctl_supported = false,
        .krkw_iosurface_supported = true,
        .perf_supported = true,
        .kernelcache__static_base = 0xfffffff007004000,
        .proc__p_list__le_prev = 0x0008,
        .proc__p_pid = 0x0068,
        .proc__p_fd__fd_ofiles = 0x00d8,
        .proc__object_size = 0x04b0,
        .task__map = 0x0028,
        .vm_map__hdr_links_prev = 0x0010,
        .vm_map__hdr_links_next = 0x0008,
        .vm_map__min_offset = 0x0010,
        .vm_map__max_offset = 0x0018,
        .vm_map__hdr_nentries = 0x0010,
        .vm_map__hdr_nentries_u64 = 0x0010,
        .vm_map__hdr_rb_head_store_rbh_root = 0x0010,
        .vm_map__pmap = 0x0040,
        .thread__thread_id = 0,
        .IOSurface__isa = 0x0,
        .IOSurface__pixelFormat = 0xa4,
        .IOSurface__allocSize = 0xac,
        .IOSurface__useCountPtr = 0xc0,
        .IOSurface__indexedTimestampPtr = 0x360,
        .IOSurface__readDisplacement = 0x14,
        .kernelcache__allproc = 0xfffffff007856188,
        .kernelcache__cdevsw = 0xfffffff0077fdeb8,
        .kernelcache__gPhysBase = 0xfffffff007116740,
        .kernelcache__gPhysSize = 0xfffffff007116748,
        .kernelcache__gVirtBase = 0xfffffff0071149f0,
        .kernelcache__perfmon_dev_open = 0xfffffff0072fb3fc,
        .kernelcache__perfmon_devices = 0xfffffff007839210,
        .kernelcache__ptov_table = 0xfffffff0070cb590,
        .kernelcache__vn_kqfilter = 0xfffffff007341bb8,
        .device__T1SZ_BOOT = 0x0019,
        .device__ARM_TT_L1_INDEX_MASK = 0x0000007000000000,
    },
};

struct dynamic_info dynamic_system_info = { 0 };

#define ARM64_LINK_ADDR dynamic_info(kernelcache__static_base)

#endif /* dynamic_info_h */
