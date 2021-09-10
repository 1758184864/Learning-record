package cn.com.scitc.studentmanager.service;

import cn.com.scitc.studentmanager.pojo.Clazz;
import org.apache.ibatis.annotations.Mapper;

import java.util.List;

@Mapper
public interface ClazzService {
    // 学生列表
    List<Clazz> listClazz();

    // 获取年级列表
    List<String> getAllGrade();

    //获取班级列表
    List<String> getAllCalzz(String grade);
}
