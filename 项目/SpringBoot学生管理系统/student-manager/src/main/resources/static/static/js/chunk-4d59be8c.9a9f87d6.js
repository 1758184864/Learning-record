(window["webpackJsonp"]=window["webpackJsonp"]||[]).push([["chunk-4d59be8c"],{2472:function(e,t,a){"use strict";a.d(t,"e",(function(){return n})),a.d(t,"f",(function(){return l})),a.d(t,"b",(function(){return o})),a.d(t,"a",(function(){return s})),a.d(t,"d",(function(){return u})),a.d(t,"c",(function(){return c}));var r=a("b775");function n(){return Object(r["a"])({url:"/clazz/list",method:"get"})}function l(e){return Object(r["a"])({url:"/clazz/update",method:"post",data:e})}function o(e){return Object(r["a"])({url:"/clazz/delete/"+e,method:"post"})}function s(e){return Object(r["a"])({url:"/clazz/add/",method:"post",data:e})}function u(){return Object(r["a"])({url:"/clazz/grades",method:"get"})}function c(e){return Object(r["a"])({url:"/clazz/clazzs?grade="+e,method:"get"})}},"49e5":function(e,t,a){"use strict";a.d(t,"c",(function(){return n})),a.d(t,"a",(function(){return l})),a.d(t,"e",(function(){return o})),a.d(t,"b",(function(){return s})),a.d(t,"d",(function(){return u}));var r=a("b775");function n(){return Object(r["a"])({url:"/student/list",method:"get"})}function l(e){return Object(r["a"])({url:"/student/add",method:"post",data:e})}function o(e){return Object(r["a"])({url:"/student/update",method:"post",data:e})}function s(e){return Object(r["a"])({url:"/student/delete/"+e,method:"post"})}function u(e){return Object(r["a"])({url:"/student/search",method:"post",data:e})}},"971a":function(e,t,a){"use strict";a.r(t);var r=function(){var e=this,t=e.$createElement,a=e._self._c||t;return a("el-form",{ref:"form",staticStyle:{width:"50%","margin-top":"20px"},attrs:{model:e.form,"label-width":"80px"}},[a("el-form-item",{attrs:{label:"姓名"}},[a("el-input",{model:{value:e.form.name,callback:function(t){e.$set(e.form,"name",t)},expression:"form.name"}})],1),a("el-form-item",{attrs:{label:"年龄"}},[a("el-input",{model:{value:e.form.age,callback:function(t){e.$set(e.form,"age",t)},expression:"form.age"}})],1),a("el-form-item",{attrs:{label:"性别"}},[a("el-radio-group",{model:{value:e.form.sex,callback:function(t){e.$set(e.form,"sex",t)},expression:"form.sex"}},[a("el-radio",{attrs:{label:"1",value:"1"}},[e._v("男")]),a("el-radio",{attrs:{label:"0",value:"0"}},[e._v("女")])],1)],1),a("el-form-item",{attrs:{label:"学号"}},[a("el-input",{model:{value:e.form.num,callback:function(t){e.$set(e.form,"num",t)},expression:"form.num"}})],1),a("el-form-item",{attrs:{label:"年级"}},[a("el-select",{attrs:{placeholder:"请选择年级"},model:{value:e.grade,callback:function(t){e.grade=t},expression:"grade"}},e._l(e.gradeList,(function(e,t){return a("el-option",{attrs:{label:e,value:e}})})),1)],1),a("el-collapse-transition",[a("el-form-item",{directives:[{name:"show",rawName:"v-show",value:e.classVisible,expression:"classVisible"}],attrs:{label:"班级"}},[a("el-select",{attrs:{placeholder:"请选择班级"},model:{value:e.form.clazz,callback:function(t){e.$set(e.form,"clazz",t)},expression:"form.clazz"}},e._l(e.clazzList,(function(e,t){return a("el-option",{attrs:{label:e,value:e}})})),1)],1)],1),a("el-form-item",{attrs:{label:"家庭住址"}},[a("el-input",{model:{value:e.form.address,callback:function(t){e.$set(e.form,"address",t)},expression:"form.address"}})],1),a("el-form-item",[a("el-button",{attrs:{type:"primary"},on:{click:e.onSubmit}},[e._v("添加")]),a("el-button",[e._v("取消")])],1)],1)},n=[],l=(a("b0c0"),a("2472")),o=a("49e5"),s={data:function(){return{classVisible:!1,gradeList:[],clazzList:[],grade:"",form:{name:"",age:"",sex:"",num:"",clazz:"",address:""}}},mounted:function(){var e=this;Object(l["d"])().then((function(t){e.gradeList=t.data.data}))},methods:{onSubmit:function(){var e=this,t=this.form.name,a=this.form.age,r=this.form.sex,n=this.form.num,l=this.grade,s=this.form.clazz,u=this.form.address;if(null===t||""===t||null===a||""===a||null===r||""===r||null===n||""===n||null===l||""===l||null===s||""===s||null===u||""===u)this.$message({message:"请填写完整的信息",type:"error"});else{var c={name:t,age:a,sex:r,num:n,grade:l,clazz:s,address:u};Object(o["a"])(c).then((function(t){e.$message({message:t.message,type:"success"}),e.form.name="",e.form.age="",e.form.sex="",e.form.num="",e.form.clazz="",e.form.address=""}))}}},watch:{grade:{handler:function(e,t){var a=this;e!=t&&(Object(l["c"])(e).then((function(e){a.clazzList=e.data.data})),this.classVisible=!0)},deep:!0}}},u=s,c=a("2877"),i=Object(c["a"])(u,r,n,!1,null,null,null);t["default"]=i.exports}}]);