package com.process.service;

import com.baomidou.mybatisplus.extension.service.IService;
import com.jc.model.process.ProcessType;

import java.util.List;

/**
 * @author John.Cena
 * @date 2023/4/13 11:06
 * @Description:
 */
public interface ProcessTypeService extends IService<ProcessType> {
    List<ProcessType> findProcessType();
}
