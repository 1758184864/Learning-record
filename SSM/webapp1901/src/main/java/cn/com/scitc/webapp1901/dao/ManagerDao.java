package cn.com.scitc.webapp1901.dao;

import cn.com.scitc.webapp1901.mapper.ManagerMapper;
import cn.com.scitc.webapp1901.model.Manager;
import cn.com.scitc.webapp1901.utils.MybatisUtil;
import org.apache.ibatis.session.SqlSession;

import java.util.List;

public class ManagerDao implements ManagerMapper {
    @Override
    public int deleteByPrimaryKey(Integer id) {
        return 0;
    }

    @Override
    public int insert(Manager record) {
        return 0;
    }

    @Override
    public Manager selectByPrimaryKey(Integer id) {
        return null;
    }

    @Override
    public int updateByPrimaryKey(Manager manager) {
        try(SqlSession session = MybatisUtil.getSqlSession()){
            ManagerMapper mapper = session.getMapper(ManagerMapper.class);
            int result = mapper.updateByPrimaryKey(manager);
            session.commit();
            return result;
        }
    }

    @Override
    public Manager findByLoginId(String loginId) {
        try(SqlSession session = MybatisUtil.getSqlSession()){
            ManagerMapper mapper = session.getMapper(ManagerMapper.class);
            return mapper.findByLoginId(loginId);
        }
    }

    @Override
    public List<Manager> selectAll() {
        try(SqlSession session = MybatisUtil.getSqlSession()){
            ManagerMapper mapper = session.getMapper(ManagerMapper.class);
            return mapper.selectAll();
        }
    }
}