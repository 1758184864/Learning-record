package cn.com.huadi.controller;

import cn.com.huadi.entity.Collect;
import cn.com.huadi.entity.Curriculum;
import cn.com.huadi.entity.Mycourse;
import cn.com.huadi.entity.User;
import cn.com.huadi.service.impl.CollectService;
import cn.com.huadi.service.impl.CurriculumService;
import cn.com.huadi.service.impl.MycourseService;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.ui.Model;
import org.springframework.web.bind.annotation.RequestMapping;
import util.ExcludeEmptyQueryWrapper;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;
import java.util.ArrayList;
import java.util.List;

/**
 * @author John.Cena
 * @date 2021/11/7 11:30
 * @Description: 主页控制器
 */
@Controller
public class IndexController {
    @Autowired
    MycourseService mycourseService;
    @Autowired
    CurriculumService curriculumService;
    @Autowired
    CollectService collectService;
    @Autowired
    CollectController collectController;

    /**
     * 跳转到用户个人中心页面
     * @return
     */
    @RequestMapping("/userCenter")
    public String userCenter() {
        return "userCenter";
    }

    /**
     * 跳转到我的课程页面
     * @param userId
     * @param model
     * @return
     */
    @RequestMapping("/course")
    public String course(String userId, Model model, HttpServletRequest request) {
        List<Integer> collects = new ArrayList<>();

        HttpSession session = request.getSession();
        User user = (User) session.getAttribute("user");
        if (user != null) {
            List<Curriculum> curriculums = collectController.getCollect(user.getId().toString());
            for (Curriculum curriculum : curriculums) {
                collects.add(curriculum.getId());
            }
            model.addAttribute("collects",collects);
        }
        System.out.println(collects);


        ExcludeEmptyQueryWrapper<Mycourse> queryWrapper = new ExcludeEmptyQueryWrapper<>();
        queryWrapper.eq("user_id", userId);

        ArrayList<Curriculum> curricula = null;
        try {
            List<Mycourse> list = mycourseService.list(queryWrapper);

            curricula = new ArrayList<>();

            for (Mycourse mycourse : list) {
                curricula.add(curriculumService.getById(mycourse.getCurriculumId()));
            }
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }

        model.addAttribute("courseList",curricula);

        return "course";
    }

    /**
     * 跳转到我的收藏页面
     * @param userId
     * @param model
     * @return
     */
    @RequestMapping("/favorites")
    public String favorites(String userId, Model model) {
        ExcludeEmptyQueryWrapper<Collect> queryWrapper = new ExcludeEmptyQueryWrapper<>();
        queryWrapper.eq("user_id",userId);
        ArrayList<Curriculum> curricula = null;
        try {
            List<Collect> list = collectService.list(queryWrapper);
            curricula = new ArrayList<>();
            for (Collect collect : list) {
                curricula.add(curriculumService.getById(collect.getCurriculumId()));
            }
        } catch (Exception e) {
            e.printStackTrace();
            return null;
        }

        model.addAttribute("courseList",curricula);
        return "favorites";
    }
}
