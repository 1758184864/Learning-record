package cn.com.scitc.studentmanager.mapper;

import cn.com.scitc.studentmanager.pojo.User;
import org.apache.ibatis.annotations.Mapper;

@Mapper
public interface UserMapper {
    // 根据token查询用户信息，用于登录
    User selectUserByToken(String token);

    // 根据用户名查询密码
    String findPassWordByUsername(String username,String password);

    // 验证通过更新token
    void createToken(String token,int user_id);

    // 根据用户名查询id
    int findIdByUsername(String username);

    // 清空token表
    void cleanToken();
}
