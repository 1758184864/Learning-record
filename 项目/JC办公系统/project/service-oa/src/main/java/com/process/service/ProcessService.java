package com.process.service;

import com.baomidou.mybatisplus.core.metadata.IPage;
import com.baomidou.mybatisplus.extension.plugins.pagination.Page;
import com.baomidou.mybatisplus.extension.service.IService;
import com.jc.vo.process.ProcessFormVo;
import com.jc.vo.process.ProcessQueryVo;
import com.jc.vo.process.ProcessVo;
import com.jc.model.process.Process;
/**
 * @author John.Cena
 * @date 2023/4/13 17:07
 * @Description:
 */
public interface ProcessService extends IService<Process> {

    IPage<ProcessVo> selectPage(Page<ProcessVo> pageParam, ProcessQueryVo processQueryVo);

    void deployByZip(String deployPath);

    void startUp(ProcessFormVo processFormVo);

    IPage<ProcessVo> findPending(Page<Process> pageParam);
}
